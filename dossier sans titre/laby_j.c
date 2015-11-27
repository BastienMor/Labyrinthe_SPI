void Labyrinthe_initialiser(){
	int i,j;
	int nombre=0;
	
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			labyrinthe[i][j].etat=nombre;
			labyrinthe[i][j].droite = 0;
			labyrinthe[i][j].gauche = 0;
			labyrinthe[i][j].haut = 0;
			labyrinthe[i][j].bas = 0;
			nombre++;
		}
	}
}

void Labyrinthe_afficher(){
	int i,j,k;
	
	for(i=0;i<N;i++){
		printf("\t");
		for(k=0;k<N;k++){
			printf("-----");
		}
		printf("-\n\t|");
		for(j=0;j<M;j++){
			printf("  %i  ", labyrinthe[i][j].etat);
			printf("|");
			
		}
		
		printf("\n");
	}
}
