/* Copyright (C) 2012  Fabrizio Gueli
 *
 * This file is part of Cuda-complex-sim
 *
 * Cuda-complex-sim is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * Cuda-complex-sim is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with Cuda-complex-sim.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
#include "device.cuh"
#include "host.hpp"
#include "graph_transf.hpp"
#include "h_barabasi_game.hpp"
#include "hygra.cuh"


int main(int argc, char** argv)
{

		bool* nodes_dev;
		Link* links_target_dev;
		bool* flagw_array;
		bool* flagr_array;
		uint32_t* counter;
		task_t* task_dev;
		task_arguments* task_args_dev;
		message_t* inbox_dev;
		n_attribute *prog;
		curandState *d_state;

//		if (argc!=3)
	//		{
//				perror("\nErrore");
//				exit(1);
//			}


//	uint32_t max_nodes=atoi(argv[1]);
//	uint8_t average_links=atoi(argv[2]);
	uint16_t supplementary_size= 10;




	uint32_t max_nodes = 1000000;
	uint8_t average_links= 2;
	uint16_t barabasi_initial_nodes=average_links+1;

	allocateDataStructures(&prog,&nodes_dev, &task_dev, &task_args_dev, &links_target_dev, &inbox_dev,max_nodes,average_links,supplementary_size,&d_state,&flagw_array,&flagr_array,&counter);
	h_allocateDataStructures(supplementary_size,max_nodes,average_links);

	Graph g = h_barabasi_game(barabasi_initial_nodes, 1, max_nodes);
	startSimulation(links_target_dev,nodes_dev,supplementary_size,g);




	srand(time(NULL));
//	Link init;
//	init.target=-1;
//	init_data<<<BLOCKS,THREADS_PER_BLOCK>>>();
//	h_initArray<bool>(false,h_nodes_array,h_max_nodes_number);
//	h_initArray<Link>(init, h_links_target_array, h_max_nodes_number*h_average_links_number);

//	adjlistToCompactList(g);

//	copyToDevice(nodes_dev,h_nodes_array , 0, h_max_nodes_number );
//	copyToDevice(links_target_dev,h_links_target_array ,0, h_max_nodes_number*h_average_links_number );

  	size_t avail;
  	size_t total;
  	cudaMemGetInfo( &avail, &total );

  	size_t used = total - avail;
  	printf("\nMemoria: totale %d, in uso %d, disponibile: %d", total, used, avail);

  	cudaEvent_t start, stop;
  	cudaEventCreate(&start);
  	cudaEventCreate(&stop);
  	// Start record
  	cudaEventRecord(start, 0);

  		message_test<<<BLOCKS,THREADS_PER_BLOCK,h_average_links_number*THREADS_PER_BLOCK*sizeof(Link)>>>();
  		message_test2nd<<<BLOCKS,THREADS_PER_BLOCK,h_average_links_number*THREADS_PER_BLOCK*sizeof(Link)>>>();
  		message_test2nd<<<BLOCKS,THREADS_PER_BLOCK,h_average_links_number*THREADS_PER_BLOCK*sizeof(Link)>>>();
  		cudaEventRecord(stop, 0);
  		cudaEventSynchronize(stop);
  		float elapsedTime;
  		cudaEventElapsedTime(&elapsedTime, start, stop); // that's our time!
  		// Clean up:
  		cudaEventDestroy(start);
  		cudaEventDestroy(stop);
  		FILE *file;
  		file=fopen("times.txt","a");
  		fprintf(file, "%f\n",elapsedTime);
  		fflush(file);
  		fclose(file);
  		cudaThreadExit();


  return 0;
}

*/
