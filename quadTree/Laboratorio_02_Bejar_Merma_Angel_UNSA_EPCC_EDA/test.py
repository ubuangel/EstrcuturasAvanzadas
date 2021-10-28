import numpy as np
import matplotlib.pyplot as plt
from matplotlib import gridspec
from quadtree import Punto, Rectangulo, QuadTree

DPI = 72

ancho, altura = 600, 400

N = 50
xs = np.random.rand(N) * ancho
ys = np.random.rand(N) * altura
puntos = [Punto(xs[i], ys[i]) for i in range(N)]

dominio = Rectangulo(Punto(ancho/2, altura/2), ancho/2, altura/2)
qtree = QuadTree(dominio)

for punto in puntos:
    qtree.insertar(punto)

print('Total puntos: ', len(qtree))

# draw rectangles
fig = plt.figure(figsize=(700/DPI, 500/DPI), dpi=DPI)
ax = plt.subplot()
ax.set_xlim(0, ancho)
ax.set_ylim(0, altura)
qtree.draw(ax)

# draw puntos
ax.scatter([p.x for p in puntos], [p.y for p in puntos], s=4)
ax.set_xticks([])
ax.set_yticks([])

# generate the range
#centro_x = np.random.rand() * ancho
#centro_y = np.random.rand() * altura
centro_x = 300
centro_y = 200

rango_ancho = np.random.rand() * min(centro_x, ancho - centro_x)
rango_altura = np.random.rand() * min(centro_y, altura - centro_y)

puntos_encontrados = []
#range = Rectangulo(Punto(centro_x, centro_y), rango_ancho, rango_altura)
#puntos_encontrados = qtree.consultarRango(range)
#radio = min(rango_ancho, rango_altura)
radio = 150
range = Rectangulo(Punto(centro_x, centro_y), radio, radio)
puntos_encontrados = qtree.consultarRadio(range, Punto(centro_x, centro_y))

print('puntos en rango:', len(puntos_encontrados))

ax.scatter([p.x for p in puntos_encontrados], [p.y for p in puntos_encontrados],
            facecolors='none', edgecolors='r', s=32)

range.draw(ax, c='r', lw=2)

ax.invert_yaxis()
plt.tight_layout()
plt.savefig('search-quadtree.png', DPI=72)
plt.show()
