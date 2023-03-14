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