#This project makes a 3D reconstruction
#of an object from its projections

import numpy as np
from mpl_toolkits.mplot3d import axes3d
import matplotlib.pyplot as plt

c1 = []; c2 = []; p1 = []; p2 = []; op = 0

# def eq_reta():
#   y = mr1(p1[0] - c1[0]) + c1[1]

while op != 5:
  print("1-Insert coordinates of camera 1")
  print("2-Insert coordinates of camera 2")
  print("3-Insert coordinates of projection 1")
  print("4-Insert coordinates of projection 2")
  print("5-Finish")
  op = int(input("Option: "))

  if op == 1:
    c1.append(float(input("x: ")))
    c1.append(float(input("y: ")))
    c1.append(float(input("z: ")))
    print(c1)

  if op == 2:
    c2.append(float(input("x: ")))
    c2.append(float(input("y: ")))
    c2.append(float(input("z: ")))
    print(c2)

  if op == 3:
    p1.append(float(input("x: ")))
    p1.append(float(input("y: ")))
    p1.append(float(input("z: ")))
    print(p1)

  if op == 4:
    p2.append(float(input("x: ")))
    p2.append(float(input("y: ")))
    p2.append(float(input("z: ")))
    print(p2)

print("\nXY plane")
mr1_xy = (p1[1]-c1[1])/(p1[0]-c1[0])
print("MR1: ", mr1_xy)
br1_xy = -1 * (mr1_xy*c1[0]-c1[1])
print("BR1: ",br1_xy)

mr2_xy = (p2[1]-c2[1])/(p2[0]-c2[0])
print("MR2: ",mr2_xy)
br2_xy = -1 * (mr2_xy*c2[0]-c2[1])
print("BR2: ", br2_xy)

#######
print("\nXZ plane")
mr1_xz = (p1[2]-c1[2])/(p1[0]-c1[0])
print("MR1: ", mr1_xz)
br1_xz = -1 * (mr1_xz*c1[0]-c1[2])
print("BR1: ",br1_xz)

mr2_xz = (p2[2]-c2[2])/(p2[0]-c2[0])
print("MR2: ", mr2_xz)
br2_xz = -1 * (mr2_xz*c2[0]-c2[2])
print("BR2: ", br2_xz)

#######
print("\nZY plane")
mr1_zy = (p1[1]-c1[1])/(p1[2]-c1[2])
print("MR1: ",mr1_zy)
br1_zy = -1 * (mr1_zy*c1[2]-c1[1])
print("BR1: ",br1_zy)

mr2_zy = (p2[1]-c2[1])/(p2[2]-c2[2])
print("MR2: ", mr2_zy)
br2_zy = -1 * (mr2_zy*c2[2]-c2[1])
print("BR2: ", br2_zy)

fig = plt.figure(figsize=(10, 8))
ax = plt.axes(projection="3d")
ax.set_title('3D plot', fontsize=18)
ax.set_xlabel('X axis', fontsize=15)
ax.set_ylabel('Y axis', fontsize=15)
ax.set_zlabel('Z axis', fontsize=15)
ax.scatter(c1[0], c1[1], c1[2], c='blue')
ax.scatter(p1[0], p1[1], p1[2], c='red')
ax.scatter(c2[0], c2[1], c2[2], c='blue')
ax.scatter(p2[0], p2[1], p2[2], c='red')

x1 = np.linspace(c1[0], p1[0])
y1 = np.linspace(c1[1], p1[1])
z1 = np.linspace(c1[2], p1[2])
ax.plot(x1, y1, z1, color='k')

x2 = np.linspace(c2[0], p2[0])
y2 = np.linspace(c2[1], p2[1])
z2 = np.linspace(c2[2], p2[2])
ax.plot(x2, y2, z2, color='k')

plt.show()

print(c1)
print(p1)

#Plano XY
x_xy = (-1*(mr2_xy*c2[0]) + c2[1] + (mr1_xy*c1[0]) - c1[1]) / (mr1_xy - mr2_xy)
y_xy = (mr1_xy*x_xy) - (mr1_xy*c1[0]) + c1[1]
print("\nCoordinates on XY plane: [", x_xy, ", ", y_xy, "]")

#Plano XZ
x_xz = (-1*(mr2_xz*c2[0]) + c2[2] + (mr1_xz*c1[0]) - c1[2]) / (mr1_xz - mr2_xz)
y_xz = (mr1_xz*x_xz) - (mr1_xz*c1[0]) + c1[2]
print("Coordinates on XZ plane: [", x_xz, ", ", y_xz, "]")

#Plano ZY
x_zy = (-1*(mr2_zy*c2[2]) + c2[1] + (mr1_zy*c1[2]) - c1[1]) / (mr1_zy - mr2_zy)
y_zy = (mr1_zy*x_zy) - (mr1_zy*c1[2]) + c1[1]
print("Coordinates on ZY plane: [", x_zy, ", ", y_zy, "]")

import os
os.system('clear') or None

x_esp = (x_xy + x_xz)/2
y_esp = (y_xy + y_zy)/2
z_esp = (y_xz + x_zy)/2

print("\n------------------- Calculando erro -------------------")
x_real = float(input("Insert X real value of the object: "))
y_real = float(input("Insert Y real value of the object: "))
z_real = float(input("Insert Z real value of the object: "))

erro_x = x_real - x_esp
erro_y = y_real - y_esp
erro_z = z_real - z_esp

erro_ab_x = abs(erro_x)
erro_ab_y = abs(erro_y)
erro_ab_z = abs(erro_z)

print("\nX error: ", erro_x)
print("Y error: ", erro_y)
print("Z error: ", erro_z)
print("\nX absolute error: ", erro_ab_x)
print("Y absolute error: ", erro_ab_y)
print("Z absolute error: ", erro_ab_z)

erro_total = (erro_ab_x + erro_ab_y + erro_ab_z)/3
print("\nTotal error = ", erro_total)