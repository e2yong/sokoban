void left(){//왼쪽으로 이동
	memcpy(for_undo_map, save_array[now_map], sizeof(save_array[now_map]));
	if(save_array[now_map][now_player[0]][now_player[1]-1] == 'O'){//이동방향이 골인지점인 경우
		save_array[now_map][now_player[0]][now_player[1]-1] = '@';
		save_array[now_map][now_player[0]][now_player[1]] = ' ';
		now_player[1]--;
	}
	else if(save_array[now_map][now_player[0]][now_player[1]-1] == ' '){//이동방향이 공백(길)인 경우
		save_array[now_map][now_player[0]][now_player[1]-1] = '@';
		save_array[now_map][now_player[0]][now_player[1]] = ' ';
		now_player[1]--;
	}
	else if(save_array[now_map][now_player[0]][now_player[1]-1] == '$'){//이동방향이 블록이고
		if(save_array[now_map][now_player[0]][now_player[1]-2] == '#'){//블록 다음칸이 벽인 경우
			print_map(now_map);
			return;
		}
		else if(save_array[now_map][now_player[0]][now_player[1]-2] == '$'){//블록 다음칸이 블록인 경우
			print_map(now_map);
			return;
		}
		else{
			save_array[now_map][now_player[0]][now_player[1]-2] = '$'; //블록 다음칸이 비어있는 경우
			save_array[now_map][now_player[0]][now_player[1]-1] = '@';
			save_array[now_map][now_player[0]][now_player[1]] = ' ';
			now_player[1]--;
		}
	}
	compare_map();
	print_map(now_map);
}
void right(){//오른쪽으로 이동, 이동방향에 대한 구현은 left함수와 동일
	memcpy(for_undo_map, save_array[now_map], sizeof(save_array[now_map]));
	if(save_array[now_map][now_player[0]][now_player[1]+1] == 'O'){
		save_array[now_map][now_player[0]][now_player[1]+1] = '@';
		save_array[now_map][now_player[0]][now_player[1]] = ' ';
		now_player[1]++;
	}
	else if(save_array[now_map][now_player[0]][now_player[1]+1] == ' '){
		save_array[now_map][now_player[0]][now_player[1]+1] = '@';
		save_array[now_map][now_player[0]][now_player[1]] = ' ';
		now_player[1]++;
	}
	else if(save_array[now_map][now_player[0]][now_player[1]+1] == '$'){
		if(save_array[now_map][now_player[0]][now_player[1]+2] == '#'){
			print_map(now_map);
			return;
		}
		else if(save_array[now_map][now_player[0]][now_player[1]+2] == '$'){
		print_map(now_map);
		return;
		}
		else{
			save_array[now_map][now_player[0]][now_player[1]+2] = '$'; 
			save_array[now_map][now_player[0]][now_player[1]+1] = '@';
			save_array[now_map][now_player[0]][now_player[1]] = ' ';
			now_player[1]++;
		}
	}
	compare_map();
	print_map(now_map);
}
void up(){//위로 이동, 이동방향에 대한 구현은 left함수와 동일
	memcpy(for_undo_map, save_array[now_map], sizeof(save_array[now_map]));
	if(save_array[now_map][now_player[0]-1][now_player[1]] == 'O'){
		save_array[now_map][now_player[0]-1][now_player[1]] = '@';
		save_array[now_map][now_player[0]][now_player[1]] = ' ';
		now_player[0]--;
	}
	else if(save_array[now_map][now_player[0]-1][now_player[1]] == ' '){
		save_array[now_map][now_player[0]-1][now_player[1]] = '@';
		save_array[now_map][now_player[0]][now_player[1]] = ' ';
		now_player[0]--;
	}
	else if(save_array[now_map][now_player[0]-1][now_player[1]] == '$'){
		if(save_array[now_map][now_player[0]-2][now_player[1]] == '#'){
			print_map(now_map);
			return;
		}
		else if(save_array[now_map][now_player[0]-2][now_player[1]] == '$'){
		print_map(now_map);
		return;
		}
		else{
			save_array[now_map][now_player[0]-2][now_player[1]] = '$'; 
			save_array[now_map][now_player[0]-1][now_player[1]] = '@';
			save_array[now_map][now_player[0]][now_player[1]] = ' ';
			now_player[0]--;
		}
	}
	compare_map();
	print_map(now_map);
}
void down(){//아래도 이동, 이동방향에 대한 구현은 left함수와 동일
	memcpy(for_undo_map, save_array[now_map], sizeof(save_array[now_map]));
	if(save_array[now_map][now_player[0]+1][now_player[1]] == 'O'){
		save_array[now_map][now_player[0]+1][now_player[1]] = '@';
		save_array[now_map][now_player[0]][now_player[1]] = ' ';
		now_player[0]++;
	}
	else if(save_array[now_map][now_player[0]+1][now_player[1]] == ' '){
		save_array[now_map][now_player[0]+1][now_player[1]] = '@';
		save_array[now_map][now_player[0]][now_player[1]] = ' ';
		now_player[0]++;
	}
	else if(save_array[now_map][now_player[0]+1][now_player[1]] == '$'){
		if(save_array[now_map][now_player[0]+2][now_player[1]] == '#'){
			print_map(now_map);
			return;
		}
		else if(save_array[now_map][now_player[0]+2][now_player[1]] == '$'){
		print_map(now_map);
		return;
		}
		else{
			save_array[now_map][now_player[0]+2][now_player[1]] = '$'; 
			save_array[now_map][now_player[0]+1][now_player[1]] = '@';
			save_array[now_map][now_player[0]][now_player[1]] = ' ';
			now_player[0]++;
		}
	}
	compare_map();
	print_map(now_map);
}

void replay(){//replay기능 
	memcpy(save_array[now_map], map_array[now_map], sizeof(map_array[now_map]));
	find_player(now_map);
	printf("replay가실행되었습니다. 게임을 다시 시작합니다.\n");
	print_map(now_map);
}
void new(){//new 함수
	now_map = 0;
	start = time(NULL);
	end = 0;
	play_time = 0;
	undo_cnt = 0;
	memcpy(for_undo_map, map_array[0], sizeof(map_array[0]));
	memcpy(save_array, map_array, sizeof(map_array));
	find_player(now_map);
	
	print_map(now_map);
}

void undo(){//undo함수,연속해서 사용 불가, 스테이지당 최대 5번 사용가능
	if(undo_cnt >= 5){
	   	printf("undo 횟수가 5회를 초과했습니다.\n");
		print_map(now_map);
	}
	else{
		memcpy(save_array[now_map], for_undo_map, sizeof(save_array[now_map]));
		undo_cnt++;
		find_player(now_map);
		printf("되돌리기가 실행되었습니다. 이 스테이지의 남은 되돌리기 횟수는 %d입니다.\n",5-undo_cnt);
		print_map(now_map);
	}
}
void save(){//저장함수
	FILE *fp;
	fp = fopen("sokoban.txt", "w");
	end = time(NULL);
	play_time = play_time + (end - start);
	int i = 0;
	char temp[20];
	while(1){
		for(int j=0; j < map_array_pnt[i]; j++){
			fputs(save_array[i][j], fp);
		}
		i++;
		if(map_array_pnt[i] == 0) {
			fputs("end\n", fp);
			sprintf(temp, "%d", now_map);
			fputs(temp, fp); fputs("\n", fp);
			sprintf(temp, "%d", play_time); 
			fputs(temp, fp); fputs("\n", fp);
			sprintf(temp, "%d", undo_cnt);	
			fputs(temp, fp); fputs("\n", fp);
			sprintf(temp,"%s", user_name);
			fputs(temp, fp); fputs("\n", fp);
			break;		
	        }

	}
}
void exit_game(){ //게임종료
	printf("good bye %s", user_name );
	save();    
                }
void rank(){   // 스테이지가 끝나면 랭킹을 저장하는 함수.
	load_rank();
	FILE *fp;
	char temp[10];
	int ti=0, ni=0, mc=0, i = 0, j;
	fp = fopen("ranking.txt", "w+");
	for(i=0; i<now_map; i++){
		fprintf(fp, "#%d\n", i);
		for(j=0; j<ranking_idx[i]; j++){
			sprintf(temp, "%d", load_time[i][j]);
			fputs(temp, fp); fputs("\n", fp);
			fputs(load_name[i][j], fp);
		}
	}
	fprintf(fp, "#%d\n", now_map);
	if(ranking_idx[now_map] == 0){
		sprintf(temp, "%d", play_time);
		fputs(temp, fp); fputs("\n", fp);
		fputs(user_name, fp); fputs("\n", fp);
	}
	else{
		for(i=0; i<ranking_idx[now_map]; i++){
			if(play_time < load_time[now_map][i]){
				sprintf(temp, "%d", play_time);
				fputs(temp, fp); fputs("\n", fp);
				fputs(user_name, fp); fputs("\n", fp);
				while((i<4) && (i<ranking_idx[now_map])){
					sprintf(temp, "%d", load_time[now_map][i]);
					fputs(temp, fp); fputs("\n", fp);
					fputs(load_name[now_map][i], fp);
					i++;
				}
			}
			else{
				sprintf(temp, "%d", load_time[now_map][i]);
				fputs(temp, fp); fputs("\n", fp);
				fputs(load_name[now_map][i], fp);
				if((i==ranking_idx[now_map]-1) && i<4){
					sprintf(temp, "%d", play_time);
					fputs(temp, fp); fputs("\n", fp);
					fputs(user_name, fp); fputs("\n", fp);
				}
			}
		}
	}
	mc = now_map + 1;
	while(1){
		if(map_array_pnt[mc] == 0) 
			break;
		fprintf(fp, "#%d\n", mc);
		if(ranking_idx[mc] == 0){
			break;
		}
		else {
			for(i=0; i<ranking_idx[mc]; i++){
				sprintf(temp, "%d", load_time[mc][i]);
				fputs(temp, fp); fputs("\n", fp);
				fputs(load_name[mc][i], fp);
			}
		}
		mc++;
	}
	fputs("@", fp);	
	fclose(fp);
}
