#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <plplot/plplot.h>

double * func(double g, double l, double theta, double thetaDot, double dt) {
    static double array[2];
    array[0] = dt*thetaDot;
    array[1] = dt*(-g/l)*cos(theta);
    return array;
};

int main() {
    double theta0 = 0.0;
    double thetaDot0 = 0.0;
    double t0 = 0.0;
    double tf = 10.0;
    double g = 9.81;
    double l = 1.0;
    double N = 1e4;
    double t[(int)N+1];
    double theta[(int)N+1];
    double thetaDot[(int)N+1];
    t[0] = t0;
    theta[0] = theta0;
    thetaDot[0] = thetaDot0;
    double * K1;
    double * K2;
    double * K3;
    double * K4;
    double k1, k2, k3, k4, l1, l2, l3, l4;
    double dt = (tf-t0)/N;
    double minTheta = 1e10;

    for (int i = 0; i < N; i++) {
        K1 = func(g, l, theta[i], thetaDot[i], dt);
        k1 = K1[0];
        l1 = K1[1];
        K2 = func(g, l, theta[i] + k1/2.0, thetaDot[i] + l1/2.0, dt);
        k2 = K2[0];
        l2 = K2[1];
        K3 = func(g, l, theta[i] + k2/2.0, thetaDot[i] + l2/2.0, dt);
        k3 = K3[0];
        l3 = K3[1];
        K4 = func(g, l, theta[i] + k3, thetaDot[i] + l3, dt);
        k4 = K4[0];
        l4 = K4[1];
        theta[i+1] = theta[i] + 1.0/6.0*(k1+2*k2+2*k3+k4);
        thetaDot[i+1] = thetaDot[i] + 1.0/6.0*(l1+2*l2+2*l3+l4);
        printf("theta[%i] is %g\n", i+1, theta[i+1]);
        if (theta[i+1] < minTheta) {
            minTheta = theta[i+1];
        }
    }

    plinit();
    plenv(-M_PI, 0, -sqrt(2*g/l), sqrt(2*g/l), 0, 0);
    pllab("theta", "thetaDot", "Simple pendulum phase plot");
    plline(N+1, theta, thetaDot); 
    plend();
    printf("minTheta is %g", minTheta);
    exit(0);
}