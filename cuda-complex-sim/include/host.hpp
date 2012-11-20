/* Copyright (C) 2012 Fabrizio Gueli
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef HOST_HPP_
#define HOST_HPP_

#include <iostream>
#include <stdint.h>
#include <stdio.h>

#include "curand_kernel.h"
#include "node.hpp"
#include "link.hpp"
#include "parameters.hpp"
#include "message.hpp"
#include "task.hpp"
#include "templates.hpp"

using namespace std;

/*
 * Initializes all data structures on host. Preallocate all needed memory.
 */

__host__ bool h_allocateDataStructures(uint16_t supplementary_size, uint32_t max_nodes, uint8_t avg_links){

	h_max_nodes_number = max_nodes;
	h_average_links_number = avg_links;
//	h_active_nodes_array_size = active_size;
	h_supplementary_links_array_size =supplementary_size;


	/* allocate nodes array */

	h_nodes_array = (bool*)malloc(max_nodes*sizeof(bool));
	if(h_nodes_array == NULL){
		cerr << "\nCouldn't allocate memory on host 1";
			return false;
		}
	printf("\nAllocated %d bytes",max_nodes*sizeof(bool));

	/* h_nodes_coord_array = (float2*)malloc(max_nodes*sizeof(float2));
			if(h_nodes_coord_array == NULL){
		cerr << "\nCouldn't allocate memory on host 2";
			return false;
		}
*/


	/* allocate links arrays */

	h_links_target_array = (Link*)malloc(max_nodes*avg_links*sizeof(Link));
	if(h_links_target_array==NULL){
		cerr << "\nCouldn't allocate memory on host 3";
				return false;
	}
	printf("\nAllocated %d bytes",max_nodes*avg_links*sizeof(Link));

	/*actives_host = (int32_t*)malloc(active_size*sizeof(int32_t));
	 * if(actives_host == NULL){
	 * cerr << "\nCouldn't allocate memory on host 4";
		return false;
	}*/


	/* Allocate messages arrays */

	h_message_array = (message_t*)malloc(max_nodes*sizeof(message_t));
	if(h_message_array == NULL){

		cerr << "\nCouldn't allocate memory on host 5";
		return false;
	}

	/* Success! */
	return true;
}



#endif /* HOST_HPP_ */
