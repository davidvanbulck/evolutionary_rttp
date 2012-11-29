/**
* @file   genotype.h
* @brief  type definitions for rttp genetic algorithm
* @author dacuna <diego.acuna@usm.cl>
*/

#ifndef GENOTIPO_H_INCLUDED
#define GENOTIPO_H_INCLUDED

#include "gengetopt/read_parameters.h"

/*
 * Individual's struct representation from a population. It contains
 * individual's genes and different measures of his fitness.
 */
typedef struct{
	int **genes;	/**< individual's genes */
	/**
	* @name individual's fitness
	*/
	/*@{*/
	double fitness;	   /**< total fitness */
	double nfitness;   /**< normalized fitness (for proportional selection) */
	double rfitness;   /**< relative fitness */
	double cfitness;   /**< cumulative fitness */
	/*@}*/
} genotype;

/*
 * This struct contains all necessary information to solve a
 * rttp instance with the genetic algorithm proposed.
 */
typedef struct{
	genotype *population; 				/**< the population for the GA */
	int popsize;          				/**< population size */
	int n_teams;          				/**< Number of teams of RTTP */
	int n_rounds;          				/**< Number of rounds of RTTP */
	int **distance_matrix;          	/**< Distance matrix D of RTTP */
	double average_distance;			/**< Average distance of teams (for fitness purposes) */
	struct gengetopt_args_info params;  /**< command line parameters such as mutation rate, crossver rate, etc. */
} rttp;

#endif
