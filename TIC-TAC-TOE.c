#include<stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>


SDL_Texture *creerT(SDL_Renderer *render,int tour)
{
	if(tour%2==0)
	    {
		SDL_Surface *img=IMG_Load("/home/ghost/Téléchargements/image_croix.png");
		SDL_Texture *tex=SDL_CreateTextureFromSurface(render,img);
		SDL_FreeSurface(img);
		return tex;
	    }
	  else
	    {
	    	SDL_Surface *img=IMG_Load("/home/ghost/Téléchargements/image_cercle_2.png");
		SDL_Texture *tex=SDL_CreateTextureFromSurface(render,img);
		SDL_FreeSurface(img);
		return tex;	
	    
	    }
}

int Pwin(char*grille,int tour)
{
	if(tour%2==0)
	   {
	   	if((grille[0]=='x' && grille[1]=='x'&& grille[2]=='x')|| (grille[3]=='x'&& grille[4]=='x'&& grille[5]=='x') || (grille[6]=='x' && grille[7]=='x' && grille[8]=='x'))
	   		return 1;
	   	if((grille[0]=='x' && grille[3]=='x'&& grille[6]=='x')|| (grille[1]=='x'&& grille[4]=='x'&& grille[7]=='x') || (grille[2]=='x' && grille[5]=='x' && grille[8]=='x'))
	   		return 1;
	   	if((grille[0]=='x' && grille[4]=='x'&&grille[8]=='x')|| (grille[2]=='x'&& grille[4]=='x'&& grille[6]=='x'))
	   		return 1;
	   }

	else
	   {
	   	if((grille[0]=='o' && grille[1]=='o'&&grille[2]=='o')|| (grille[3]=='o'&& grille[4]=='o'&& grille[5]=='o') || (grille[6]=='o' && grille[7]=='o' && grille[8]=='o'))
	   		return 2;
	   	if((grille[0]=='o' && grille[3]=='o'&&grille[6]=='o')|| (grille[1]=='o'&& grille[4]=='o'&& grille[7]=='o') || (grille[2]=='o' && grille[5]=='o' && grille[8]=='o'))
	   		return 2;
	   	if((grille[0]=='o' && grille[4]=='o'&&grille[8]=='o')|| (grille[2]=='o'&& grille[4]=='o'&& grille[6]=='o'))
	   		return 2;	   			   	
	   }

}
int main(int argc,char *argv[])
{
int tour=0;
SDL_Window *fenetre=NULL;
SDL_Renderer *rendu=NULL;
SDL_Init(SDL_INIT_VIDEO);
char grille[10]="";
SDL_Rect rect[3],ect[3],ct[3];
for(int i=0;i<3;i++)
{
	rect[i].x=0+(155*i);
	rect[i].y=0;
	rect[i].w=150;
	rect[i].h=150;
	ect[i].x=0+(155*i);
	ect[i].y=155;
	ect[i].w=150;
	ect[i].h=150;
	ct[i].x=0+(155*i);
	ct[i].y=155*2;
	ct[i].w=150;
	ct[i].h=150;
}
SDL_Event event;

fenetre=SDL_CreateWindow("TIC-TAC-TOE",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,460,460,0);
rendu=SDL_CreateRenderer(fenetre,-1,SDL_RENDERER_ACCELERATED);
SDL_SetRenderDrawColor(rendu,255,255,255,SDL_ALPHA_OPAQUE);
SDL_RenderFillRects(rendu,rect,3);
SDL_RenderFillRects(rendu,ect,3);
SDL_RenderFillRects(rendu,ct,3);
SDL_RenderPresent(rendu);
SDL_bool launch=SDL_TRUE;
while(launch)
{
	SDL_WaitEvent(&event);
	switch(event.type)
		{
			case SDL_QUIT:
				launch=0;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if(event.button.button==SDL_BUTTON_LEFT && tour<9){
					if(event.button.y>=0 && event.button.y<=150)
						{
							if(event.button.x>=0 && event.button.x<=150)
							{
								if(grille[0]!='x' && grille[0]!='o')
								{		
									SDL_RenderCopy(rendu,creerT(rendu,tour),NULL,&rect[0]);
									SDL_RenderPresent(rendu);
									if(tour%2==0)
									{
										grille[0]='x';
										if(Pwin(grille,tour)==1)
										{
										   SDL_Log("Joueur1 a gagner");
										   launch=SDL_FALSE;
										}
										tour++;
									}
									else
									{
										grille[0]='o';
										if(Pwin(grille,tour)==2)
										{
										   SDL_Log("Joueur2 a gagner");
										   launch=SDL_FALSE;
										}
										tour++;
									}			
								}						
							}
							else if(event.button.x>155 && event.button.x<=305)
							{
								if(grille[1]!='x' && grille[1]!='o')
								{		
									SDL_RenderCopy(rendu,creerT(rendu,tour),NULL,&rect[1]);
									SDL_RenderPresent(rendu);
									if(tour%2==0)
									{
										grille[1]='x';
										if(Pwin(grille,tour)==1)
										{
										   SDL_Log("Joueur1 a gagner");
										   launch=SDL_FALSE;
										}
										tour++;
									}
									else
									{
										grille[1]='o';
										if(Pwin(grille,tour)==2)
										{
										   SDL_Log("Joueur2 a gagner");
										   launch=SDL_FALSE;
										}
										tour++;
									}			
								}											
							}
							else if(event.button.x>305 && event.button.x<=460)
							{
								if(grille[2]!='x' && grille[2]!='o')
								{		
									SDL_RenderCopy(rendu,creerT(rendu,tour),NULL,&rect[2]);
									SDL_RenderPresent(rendu);
									if(tour%2==0)
									{
										grille[2]='x';
										if(Pwin(grille,tour)==1)
										{
										   SDL_Log("Joueur1 a gagner");
										   launch=SDL_FALSE;
										}
										tour++;
									}
									else
									{
										grille[2]='o';
										if(Pwin(grille,tour)==2)
										{
										   SDL_Log("Joueur2 a gagner");
										   launch=SDL_FALSE;
										}
										tour++;
									}			
								}								
							}		
						}
					else if (event.button.y>155 && event.button.y<=305)
						{
							if(event.button.x>=0 && event.button.x<=150)
							{
								if(grille[3]!='x' && grille[3]!='o')
								{		
									SDL_RenderCopy(rendu,creerT(rendu,tour),NULL,&ect[0]);
									SDL_RenderPresent(rendu);
									if(tour%2==0)
									{
										grille[3]='x';
										if(Pwin(grille,tour)==1)
										{
										   SDL_Log("Joueur1 a gagner");
										   launch=SDL_FALSE;
										}
										tour++;
									}
									else
									{
										grille[3]='o';
										if(Pwin(grille,tour)==2)
										{
										   SDL_Log("Joueur2 a gagner");
										   launch=SDL_FALSE;
										}
										tour++;
									}			
								}			
							}
						
							else if(event.button.x>155 && event.button.x<=305)
							{
								if(grille[4]!='x' && grille[4]!='o')
								{		
									SDL_RenderCopy(rendu,creerT(rendu,tour),NULL,&ect[1]);
									SDL_RenderPresent(rendu);
									if(tour%2==0)
									{
										grille[4]='x';
										if(Pwin(grille,tour)==1)
										{
										   SDL_Log("Joueur1 a gagner");
										   launch=SDL_FALSE;
										}
										tour++;
									}
									else
									{
										grille[4]='o';
										if(Pwin(grille,tour)==2)
										{
										   SDL_Log("Joueur2 a gagner");
										   launch=SDL_FALSE;
										}
										tour++;
									}			
								}	
							}
							else if(event.button.x>305 && event.button.x<=460)
							{
								if(grille[5]!='x' && grille[5]!='o')
								{		
									SDL_RenderCopy(rendu,creerT(rendu,tour),NULL,&ect[2]);
									SDL_RenderPresent(rendu);
									if(tour%2==0)
									{
										grille[5]='x';
										if(Pwin(grille,tour)==1)
										{
										   SDL_Log("Joueur1 a gagner");
										   launch=SDL_FALSE;
										}
										tour++;
									}
									else
									{
										grille[5]='o';
										if(Pwin(grille,tour)==2)
										{
										   SDL_Log("Joueur2 a gagner");
										   launch=SDL_FALSE;
										}
										tour++;
									}			
								}							
							}							
						}
					else if (event.button.y>310 && event.button.y<=460)			
						 {
							if(event.button.x>=0 && event.button.x<=150)
							{
								if(grille[6]!='x' && grille[6]!='o')
								{		
									SDL_RenderCopy(rendu,creerT(rendu,tour),NULL,&ct[0]);
									SDL_RenderPresent(rendu);
									if(tour%2==0)
									{
										grille[6]='x';
										if(Pwin(grille,tour)==1)
										{
										   SDL_Log("Joueur1 a gagner");
										   launch=SDL_FALSE;
										}										
										tour++;
									}
									else
									{
										grille[6]='o';
										if(Pwin(grille,tour)==2)
										{
										   SDL_Log("Joueur2 a gagner");
										   launch=SDL_FALSE;
										}
										tour++;
									}			
								}		
							}
							else if(event.button.x>155 && event.button.x<=305)
							{
								if(grille[7]!='x' && grille[7]!='o')
								{		
									SDL_RenderCopy(rendu,creerT(rendu,tour),NULL,&ct[1]);
									SDL_RenderPresent(rendu);
									if(tour%2==0)
									{
										grille[7]='x';
										if(Pwin(grille,tour)==1)
										{
										   SDL_Log("Joueur1 a gagner");
										   launch=SDL_FALSE;
										}										
										tour++;
									}
									else
									{
										grille[7]='o';
										if(Pwin(grille,tour)==2)
										{
										   SDL_Log("Joueur2 a gagner");
										   launch=SDL_FALSE;
										}										
										tour++;

									}			
								}	
							}
							else if(event.button.x>305 && event.button.x<=460)
							{
								if(grille[8]!='x' && grille[8]!='o')
								{		
									SDL_RenderCopy(rendu,creerT(rendu,tour),NULL,&ct[2]);
									SDL_RenderPresent(rendu);
									if(tour%2==0)
									{
										grille[8]='x';
										if(Pwin(grille,tour)==1)
										{
										   SDL_Log("Joueur1 a gagner");
										   launch=SDL_FALSE;
										}
										tour++;
									}
									else
									{
										grille[8]='o';
										if(Pwin(grille,tour)==2)
										{
										   SDL_Log("Joueur2 a gagner");
										   launch=SDL_FALSE;
										}
										tour++;								
									}			
								}							
							}
			}
	}
	else if(event.button.button==SDL_BUTTON_LEFT || tour==9)
	    {
	    	SDL_Log("Match nul");
	    	launch=SDL_FALSE;
	    }
}
}
SDL_Delay(3000);
SDL_DestroyRenderer(rendu);
SDL_DestroyWindow(fenetre);
SDL_Quit();
}
