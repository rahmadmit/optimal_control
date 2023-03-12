#pragma once
#include "classic_newton.h"

double local_norm(Matrix jacoby, Vector residuals);

Vector modified_newton(double psi_u_norm, double psi_v_norm, double psi_R_norm, double T_norm);

