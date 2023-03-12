#pragma once
#include "RK4_Solver.h"
#include <fstream>
#include <tuple>

using ClassicNewtonResponse = tuple<Matrix, Vector, Vector>;

// Начальные значени
const double u0 = 0.0;
const double v0 = 29.8E3;
// const double R0 = 1.496E11;
const double phi0 = 0.0;

// Конечные значения
const double u1 = 0.0;
const double v1 = 24.1E3;
const double R1 = 2.279E11;
const double psi_phi1 = 0.0;


// Параметры пристрелки
const double psi_u0 = 695.0;
const double psi_v0 = 1383.0;
const double psi_R0 = -0.0001;
const double T0 = 60 * 60 * 24 * 400.0;

const double dx = 1E-6;

Vector RK4(double psi_u_norm, double psi_v_norm, double psi_R_norm, double T_norm);

void RK4_final_print(double psi_u_norm, double psi_v_norm, double psi_R_norm, double T_norm);

Matrix form_residuals_matrix(double psi_u_norm, double psi_v_norm, double psi_R_norm, double T_norm);

Matrix form_Jacobi_matrix(Matrix residuals);

ClassicNewtonResponse classic_newton(double psi_u_norm, double psi_v_norm, double psi_R_norm, double T_norm);