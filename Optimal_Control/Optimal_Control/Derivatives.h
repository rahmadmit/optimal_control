#pragma once
#include "Vector.h"

const double A0 = 0.0059361;
const double alpha = 0.001;
const double R0 = 149.6 * 1000000000;

double d_u(double v, double R, double theta);

double d_v(double u, double v, double R, double theta);

double d_R(double u);

double d_phi(double v, double R);

double d_psi_u(double psi_r, double psi_v, double v, double R);

double d_psi_v(double psi_u, double v, double R, double psi_v, double u);

double d_psi_R(double psi_u, double v, double R, double theta, double psi_v, double u);

double d_psi_phi();

double angle(double psi_u, double psi_v);

Vector func(Vector X, double T);

double H(Vector X);