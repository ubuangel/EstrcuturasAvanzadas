
import numpy as np
import math

class Punto:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    def distanciaCentro(self, centro):
        return math.sqrt((centro.x-self.x)**2 + (centro.y-self.y)**2)

class Rectangulo:
    def __init__(self, centro, ancho, altura):
        self.centro = centro
        self.ancho = ancho
        self.altura = altura
        self.oeste = centro.x - ancho
        self.este = centro.x + ancho
        self.norte = centro.y - altura
        self.sur = centro.y + altura

    def contienePunto(self, punto):
        return (self.oeste <= punto.x < self.este and 
                self.norte <= punto.y < self.sur)
    
    def interseccion(self, range):
        return not (range.oeste > self.este or
                    range.este < self.oeste or
                    range.norte > self.sur or
                    range.sur < self.norte)
    

    def draw(self, ax, c='k', lw=1, **kwargs):
        x1, y1 = self.oeste, self.norte
        x2, y2 = self.este, self.sur
        ax.plot([x1,x2,x2,x1,x1], [y1,y1,y2,y2,y1], c=c, lw=lw, **kwargs)

class QuadTree:
    def __init__(self, limite, capacidad = 4):
        self.limite = limite
        self.capacidad = capacidad
        self.puntos = []
        self.divided = False

    def insertar(self, punto):
        # if the punto is in the range of current quadTree
        if not self.limite.contienePunto(punto):
            return False
        
        # if has not reached capcaity
        if len(self.puntos) < self.capacidad:
            self.puntos.append(punto)
            return True
        
        if not self.divided:
            self.divide()

        if self.nw.insertar(punto):
            return True
        elif self.ne.insertar(punto):
            return True
        elif self.sw.insertar(punto):
            return True
        elif self.se.insertar(punto):
            return True

        return False
    
    def consultarRango(self, range):
        puntos_encontrados = []

        if not self.limite.interseccion(range):
            return []
        
        for punto in self.puntos:
            if range.contienePunto(punto):
                puntos_encontrados.append(punto)
        
        if self.divided:
            puntos_encontrados.extend(self.nw.consultarRango(range))
            puntos_encontrados.extend(self.ne.consultarRango(range))
            puntos_encontrados.extend(self.sw.consultarRango(range))
            puntos_encontrados.extend(self.se.consultarRango(range))
        
        return puntos_encontrados
    
    def consultarRadio(self, range, centro):
        puntos_encontrados = []

        if not self.limite.interseccion(range):
            return []
        
        for punto in self.puntos:
            if range.contienePunto(punto) and punto.distanciaCentro(centro) <= range.ancho:
                puntos_encontrados.append(punto)
        
        if self.divided:
            puntos_encontrados.extend(self.nw.consultarRadio(range, centro))
            puntos_encontrados.extend(self.ne.consultarRadio(range, centro))
            puntos_encontrados.extend(self.sw.consultarRadio(range, centro))
            puntos_encontrados.extend(self.se.consultarRadio(range, centro))
        
        return puntos_encontrados

    def divide(self):
        centro_x = self.limite.centro.x
        centro_y = self.limite.centro.y
        nuevo_ancho = self.limite.ancho / 2
        nuevo_altura = self.limite.altura / 2

        nw = Rectangulo(Punto(centro_x - nuevo_ancho, centro_y - nuevo_altura), nuevo_ancho, nuevo_altura)
        self.nw = QuadTree(nw)

        ne = Rectangulo(Punto(centro_x + nuevo_ancho, centro_y - nuevo_altura), nuevo_ancho, nuevo_altura)
        self.ne = QuadTree(ne)

        sw = Rectangulo(Punto(centro_x - nuevo_ancho, centro_y + nuevo_altura), nuevo_ancho, nuevo_altura)
        self.sw = QuadTree(sw)

        se = Rectangulo(Punto(centro_x + nuevo_ancho, centro_y + nuevo_altura), nuevo_ancho, nuevo_altura)
        self.se = QuadTree(se)

        self.divided = True

    def __len__(self):
        count = len(self.puntos)
        if self.divided:
            count += len(self.nw) + len(self.ne) + len(self.sw) + len(self.se) 
        
        return count
    
    def draw(self, ax):
        self.limite.draw(ax)

        if self.divided:
            self.nw.draw(ax)
            self.ne.draw(ax)
            self.se.draw(ax)
            self.sw.draw(ax)
