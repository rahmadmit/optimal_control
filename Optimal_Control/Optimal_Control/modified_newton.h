#pragma once
#include "classic_newton.h"

using LocalNormFunc = double(*) (Matrix&, Vector&);

double local_norm(Matrix& jacoby, Vector& residuals);

double local_norm_func(Matrix& m, Vector& v);

Vector GoldenSectionSearch(LocalNormFunc func, Matrix& m, Vector& left, Vector& right, int iter_num = 10);

Vector modified_newton(double psi_u_norm, double psi_v_norm, double psi_R_norm, double T_norm);

