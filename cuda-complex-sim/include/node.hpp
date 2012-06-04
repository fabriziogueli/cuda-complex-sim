/* Copyright (C) 2012 Carmelo Migliore, Fabrizio Gueli
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

#ifndef NODE_HPP_
#define NODE_HPP_

#include <stdint.h>

#include "math.h"
#include "link.hpp"
#include "parameters.hpp"
#include "node_resource.hpp"


/*
 * Class that implements a node's concept.
 */


struct Node {
	uint32_t id;     												// node's id
	float x, y;													// node's coordinates
	NodeResource res;											// node's resources

	/*
	 * Node constructor
	 */
	__device__ Node(uint32_t node_index, float coord_x, float coord_y, NodeResource r){
		id=node_index;
		x=coord_x;
		y=coord_y;
		res=r;
	}

	/*
	 * Calculate Euclidean distance of the node from the given coordinates
	 */
	__device__ float calculateDistance(float targ_x, float targ_y){
		return sqrtf(powf(x-targ_x,2)+powf(y-targ_y,2));
	}

	/*
	 * 	Create a node that is NOT the first of the graph and add it to the nodes array. Node creation can be done in parallel.
	 */

	__device__ static void addNode(unsigned int id, float x, float y, NodeResource nr){
		Node node(id,x,y,nr);
		nodes_dev_array[id]=node;
		Node* neighbour;
		if(id!=0){
			neighbour=&nodes_dev_array[id-1];
			links_dev_array[id*max_links_number].target=neighbour;											// first neighbour is assigned to connect the node to the net. It is the the previous node on the nodes array.
			links_dev_array[id*max_links_number].weight=node.calculateDistance(neighbour->x,neighbour->y);
		}
	}

	__device__ bool addLink(Node* trg, float distance);
	/*
	__device__ message_t readMessage();				// da implementare qui per essere inline
	__device__ bool sendMessage(message_t m, Vertex* target);
	__device__ void discovery();
	*/
};

#endif /* NODES_HPP_ */
