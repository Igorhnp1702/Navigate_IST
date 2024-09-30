void DFS(ProbInfo* prob, int row, int col, int energy, Cel_List** c_list) {

    if (row >= 1 && row <= prob->L && col >= 1 && col <= prob->C) {

        int index = (row - 1) * prob->C + col - 1;

        if (index >= 0 && index < prob->diamond_size && prob->diamond_vect[index].energy == energy) {

            Cel_List* new_cell = (Cel_List*)calloc(1, sizeof(Cel_List));
            (*new_cell)->celula.row = row;
            (*new_cell)->celula.col = col;
            (*new_cell)->next = *c_list;
            *c_list = new_cell;

            DFS(prob, row - 1, col, energy, c_list);
            DFS(prob, row + 1, col, energy, c_list);
            DFS(prob, row, col - 1, energy, c_list);
            DFS(prob, row, col + 1, energy, c_list);
        }
    }
}