# N-puzzle
An IA that resolves N-puzzles with an A* algorithm.

#
- various puzzle sizes
- initial state randomly determined states autogenerated or from input file
- transition cost : 1
- 3 heuristic functions. Manhattan-distance is mandatory.
- user may choose the heuristic function among those
- output :nb of states ever selected in the "opened" set (complexity in time)
- Max nb of states ever represented in memory at the same time (complexity in size)
- nb of moves from initial to final state according to the search
- ordered sequence of states that make up the solution, according to the search
- if the puzzle is unsolvable, inform user and quit





Optimization :
- pas faire de racine carré dans l'euclidien	# FAIT
- modifié la distanceTo seulement avec les deux pieces qui changent et ne pas tout recalculer

- inverser index et value dans le vector de map
	-> à migrer : {Map::euclideanDistance, Map::manhattanDistance, Map::moves}
	-> déja migré : {main::createMap, main::createRefMap, Map::operator<< (With Patch)}
	-> patch : reverseMap function

	-> inVect  NE PAS FAIRE DE DISTANCE ABRUTI !!!!!!!!!!!!!!!!!!
	-> map en hash
