from math import cos, pi, sin
from matplotlib import animation
from matplotlib.animation import FuncAnimation
import matplotlib.pyplot as plt
import numpy as np

PATH_TO_DIRECT_DATA = "C:\\Users\\Пользователь\\source\\git_repos\\optimal_control\\Optimal_Control\\Optimal_Control\\"
PATH_TO_REVERSE_DATA = "C:\\Users\\Пользователь\\source\\git_repos\\optimal_control\\Optimal_Control\\Optimal_Control\\"

d_data = []

with open(PATH_TO_DIRECT_DATA + "result.txt", "r") as f:
    d_data = f.readlines()


d_data = d_data[1:]
U = []
V = []
R = []
Phi = []

Psi_u = []
Psi_v = []
Psi_R = []
Psi_phi = []

H = []
Teta = []
Teta_grad = []
t_abs = []
t_sut = []

for line in d_data:
    s = list(map(float, line.split()))
    U.append(s[2])
    V.append(s[3])
    R.append(s[4])
    Phi.append(s[5])

    Psi_u.append(s[6])
    Psi_v.append(s[7])
    Psi_R.append(s[8])
    Psi_phi.append(s[9])

    H.append(s[10])
    Teta.append(s[11])
    Teta_grad.append(s[12])
    t_abs.append(s[13])
    t_sut.append(s[13] / 86400)


r_data = []

with open(PATH_TO_REVERSE_DATA + "reverse_result.txt", "r") as f:
    r_data = f.readlines()

r_data = r_data[1:]
r_U = []
r_V = []
r_R = []
r_Phi = []

r_Psi_u = []
r_Psi_v = []
r_Psi_R = []
r_Psi_phi = []

r_H = []
r_Teta = []
r_Teta_grad = []
r_t_abs = []
r_t_sut = []

for line in d_data:
    s = list(map(float, line.split()))
    r_U.append(s[2])
    r_V.append(s[3])
    r_R.append(s[4])
    r_Phi.append(s[5])

    r_Psi_u.append(s[6])
    r_Psi_v.append(s[7])
    r_Psi_R.append(s[8])
    r_Psi_phi.append(s[9])

    r_H.append(s[10])
    r_Teta.append(s[11])
    r_Teta_grad.append(s[12])
    r_t_abs.append(s[13])
    r_t_sut.append(s[13] / 86400)

fig, ax = plt.subplots()

ax.plot(t_sut, U, linewidth=4, color="red")
ax.plot(t_sut, r_U, linewidth = 5, linestyle="dashed", color="black")
ax.grid()

max_u = max(np.abs(U))

ax.arrow(0, 0, 405, 0, width=0.017 / 2 * max_u, facecolor="black", edgecolor=None, head_length=10)
ax.arrow(0, 0, 0, max_u, width=405 * 0.01 / 2, facecolor="black", edgecolor=None, head_length=0.05*max(U))

ax.legend(["u - Прямой расчет", "u - Обратной расчет"])
plt.savefig(PATH_TO_DIRECT_DATA + "U.png")












fig, ax = plt.subplots()

ax.plot(t_sut, V, linewidth=4, color="red")
ax.plot(t_sut, r_V, linewidth = 5, linestyle="dashed", color="black")
ax.grid()

max_u = max(np.abs(V))

ax.arrow(0, 0, 405, 0, width=0.017 / 2 * max_u, facecolor="black", edgecolor=None, head_length=10)
ax.arrow(0, 0, 0, max_u, width=405 * 0.01 / 2, facecolor="black", edgecolor=None, head_length=0.05*max(V))

ax.legend(["v - Прямой расчет", "v - Обратной расчет"])
plt.savefig(PATH_TO_DIRECT_DATA + "V.png")






fig, ax = plt.subplots()

ax.plot(t_sut, R, linewidth=4, color="red")
ax.plot(t_sut, r_R, linewidth = 5, linestyle="dashed", color="black")
ax.grid()

max_u = max(np.abs(R))

ax.arrow(0, 0, 405, 0, width=0.017 / 2 * max_u, facecolor="black", edgecolor=None, head_length=10)
ax.arrow(0, 0, 0, max_u, width=405 * 0.01 / 2, facecolor="black", edgecolor=None, head_length=0.05*max(R))

ax.legend(["R - Прямой расчет", "R - Обратной расчет"])
plt.savefig(PATH_TO_DIRECT_DATA + "R.png")






fig, ax = plt.subplots()

ax.plot(t_sut, Phi, linewidth=4, color="red")
ax.plot(t_sut, r_Phi, linewidth = 5, linestyle="dashed", color="black")
ax.grid()

max_u = max(np.abs(Phi))

ax.arrow(0, 0, 405, 0, width=0.017 / 2 * max_u, facecolor="black", edgecolor=None, head_length=10)
ax.arrow(0, 0, 0, max_u, width=405 * 0.01 / 2, facecolor="black", edgecolor=None, head_length=0.05*max(Phi))

ax.legend(["Phi - Прямой расчет", "Phi - Обратной расчет"])
plt.savefig(PATH_TO_DIRECT_DATA + "Phi.png")






fig, ax = plt.subplots()

ax.plot(t_sut, Psi_u, linewidth=4, color="red")
ax.plot(t_sut, r_Psi_u, linewidth = 5, linestyle="dashed", color="black")
ax.grid()

max_u = max(np.abs(Psi_u))

ax.arrow(0, 0, 405, 0, width=0.017 / 2 * max_u, facecolor="black", edgecolor=None, head_length=10)
ax.arrow(0, -1900, 0, max_u + 850, width=405 * 0.01 / 2, facecolor="black", edgecolor=None, head_length=0.05*max(Psi_u))

ax.legend(["Psi_u - Прямой расчет", "Psi_u - Обратной расчет"])
plt.savefig(PATH_TO_DIRECT_DATA + "Psi_u.png")










fig, ax = plt.subplots()

ax.plot(t_sut, Psi_v, linewidth=4, color="red")
ax.plot(t_sut, r_Psi_v, linewidth = 5, linestyle="dashed", color="black")
ax.grid()

max_u = max(np.abs(Psi_v))

ax.arrow(0, 0, 405, 0, width=0.017 / 2 * max_u, facecolor="black", edgecolor=None, head_length=10)
ax.arrow(0, 0, 0, max_u, width=405 * 0.01 / 2, facecolor="black", edgecolor=None, head_length=0.05*max(Psi_v))

ax.legend(["Psi_v - Прямой расчет", "Psi_v - Обратной расчет"])
plt.savefig(PATH_TO_DIRECT_DATA + "Psi_v.png")





fig, ax = plt.subplots()

ax.plot(t_sut, Psi_R, linewidth=4, color="red")
ax.plot(t_sut, r_Psi_R, linewidth = 5, linestyle="dashed", color="black")
ax.grid()

max_u = max(np.abs(Psi_R))

ax.arrow(0, 0, 405, 0, width=0.017 / 2 * max_u, facecolor="black", edgecolor=None, head_length=10)
ax.arrow(0, 0, 0, max_u, width=405 * 0.01 / 2, facecolor="black", edgecolor=None, head_length=0.05*max(Psi_R))

ax.legend(["Psi_R - Прямой расчет", "Psi_R - Обратной расчет"])
plt.savefig(PATH_TO_DIRECT_DATA + "Psi_R.png")





fig, ax = plt.subplots()

ax.plot(t_sut, H, linewidth=4, color="red")
ax.plot(t_sut, r_H, linewidth = 5, linestyle="dashed", color="black")
ax.grid()

max_u = 1

ax.arrow(0, 0, 405, 0, width=0.017 / 2 * max_u, facecolor="black", edgecolor=None, head_length=10)
ax.arrow(0, -0.5, 0, max_u, width=405 * 0.01 / 2, facecolor="black", edgecolor=None, head_length=0.1)

ax.legend(["H - Прямой расчет", "H - Обратной расчет"])
plt.savefig(PATH_TO_DIRECT_DATA + "H.png")







fig, ax = plt.subplots()

ax.plot(t_sut, Teta_grad, linewidth=4, color="red")
ax.plot(t_sut, r_Teta_grad, linewidth = 5, linestyle="dashed", color="black")
ax.grid()

max_u = max(np.abs(Teta_grad))

ax.arrow(0, 0, 405, 0, width=0.017 / 2 * max_u, facecolor="black", edgecolor=None, head_length=10)
ax.arrow(0, - max_u, 0, max_u + 10, width=405 * 0.01 / 2, facecolor="black", edgecolor=None, head_length=0.1)

ax.legend(["Teta - Прямой расчет", "Teta - Обратной расчет"])
plt.savefig(PATH_TO_DIRECT_DATA + "Teta.png")



Sun_X = [0] * 1001
Sun_Y = [0] * 1001


Mars_x = [R[1000] * cos(i * 2 * pi / 1000) for i in range(1001)]
Mars_y = [R[1000] * sin(i * 2 * pi / 1000) for i in range(1001)]

Earth_x = [R[0] * cos(i * 2 * pi / 1000) for i in range(1001)]
Earth_y = [R[0] * sin(i * 2 * pi / 1000) for i in range(1001)]

x = [R[i] * cos(Phi[i]) for i in range(1001)]
y = [R[i] * sin(Phi[i]) for i in range(1001)]

fig, ax = plt.subplots()

ax.axis("equal")

ax.plot(Sun_X, Sun_Y, marker="o", markersize=20, markeredgecolor="yellow", markerfacecolor="yellow")
ax.plot(Mars_x, Mars_y, color="red")
ax.plot(Earth_x, Earth_y, color="blue")
ax.plot(x, y, color="black")

ax.legend(["Солнце", "Марс", "Земля", "Траектория полета"])
plt.savefig(PATH_TO_DIRECT_DATA + "trajectory.png")








fig = plt.figure()
ax = plt.axes(xlim=(-1.1*R[1000], 1.1*R[1000]), ylim=(-1.1*R[1000], 1.1*R[1000]))
plt.axis("scaled")
line, = ax.plot([], [], lw=1, color="black")
line2, = ax.plot([], [], lw=1, color="blue")
line3, = ax.plot([], [], lw=1, color="red")
line5, = ax.plot([], [], marker="o", markersize=10, markeredgecolor="blue", markerfacecolor="blue")
line6, = ax.plot([], [], marker="o", markersize=8, markeredgecolor="red", markerfacecolor="red")
line4, = ax.plot([], [], marker="o", markersize=5, markeredgecolor="black", markerfacecolor="black")
 
def init():
    line.set_data([], [])
    line2.set_data([], [])
    line3.set_data([], [])
    line4.set_data([], [])
    line5.set_data([], [])
    line6.set_data([], [])
    return line, line2, line3, line5, line6, line4

def animate(i):
    a = [R[i] * cos(Phi[i])]
    b = [R[i] * sin(Phi[i])]
# 34945083/1000*(29.8*10^3/(149.6*10^9)))*(i-1
    a_e = [R[0] * cos((34945083/1000*(29.8*10 ** 3/(149.6*10 ** 9)))*(i))]
    b_e = [R[0] * sin((34945083/1000*(29.8*10 ** 3/(149.6*10 ** 9)))*(i))]

    a_m = [R[1000] * cos((34945083/1000*(24.1*10 ** 3/(227.9*10 ** 9)))*(i) + 0.6152)]
    b_m = [R[1000] * sin((34945083/1000*(24.1*10 ** 3/(227.9*10 ** 9)))*(i) + 0.6152)]

    line.set_data(x, y,)
    line2.set_data(Earth_x, Earth_y)
    line3.set_data(Mars_x, Mars_y)
    line5.set_data(a_e, b_e)
    line4.set_data(a, b)
    line6.set_data(a_m, b_m)
    return line, line2, line3, line5, line6, line4


anim = FuncAnimation(fig, animate, init_func=init,
                               frames=1001, interval=1, blit=True, repeat_delay=10)
 
writergif = animation.PillowWriter(fps=20)
anim.save(PATH_TO_DIRECT_DATA + 'trajectory.gif', writer=writergif)