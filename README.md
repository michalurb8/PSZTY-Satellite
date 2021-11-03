# PSZTY-Satellite
A project for Introduction to AI classes.

## Problem formulation
We are given a set of planets on circular orbits of different radii, each with identical mass, different speed.
This whole universe is 2d. There is one home planet and one target planet.
The goal is to find the optimal rocket launch time, launch angle and launch velocity from the home planet, so that the rocket eventually arrives at the target planet, preferably with shortest flight times.
The rocket interacts gravitationally with all the planets. The rocket has no propellant and its trajectory depends only on its initial velocity and gravitational intractions.
A simple genetic algorithm is used to find the optimal solution. Many rockets are launched together, the best are chosen and reproduced.
