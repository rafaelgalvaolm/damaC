#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<windows.h>



void display(char tabuleiro[8][8])
{
    int i;
    printf("\n");
    sleep(2);
    setclr(31);
    printf("\a");
    for(i=0;i<8;)
    {
        printf("\n  +--+--+--+--+--+--+--+--+");
        printf("\n%d | %c| %c| %c| %c| %c| %c| %c| %c|",i + 1,tabuleiro[i][0],tabuleiro[i][1],tabuleiro[i][2],tabuleiro[i][3],tabuleiro[i][4],tabuleiro[i][5],tabuleiro[i][6],tabuleiro[i][7]);
        i++;
    }
    printf("\n  +--+--+--+--+--+--+--+--+");
    printf("\n    A  B  C  D  E  F  G  H");
}
int main()
{
    intro:;

    FILE *f;

    char jogador1[25],jogador2[25],nhigh[25];
    int i,j,x,y,dir,pla,pontuacao=0,opo,yolo=0,limite=0;
    char tabuleiro[8][8],A,B,pos[2];

    printf("\n\t\t\t\t\t----------------------------------");
    printf("\n\t\t\t\t\t\t Historico:");
    f=fopen("F:\\pontuacao.txt","rb");
    if(f==NULL)
    {
        printf("arquivo nao existe \n");
    }

    fprintf(f,"\n %s = %d",nhigh,pontuacao);
    fclose(f);
    printf("\n\t\t\t\t\t-----------------------------------");


    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            tabuleiro[i][j]=' ';
        }
    }
    setclr(34);
    printf("\n\n\t\t\t\t\t BEM-VENDO AO JOGO DE DAMA DO LEO DOTEIRO! \n\n\n");

    setclr(35);

    printf("\a");
    printf("\n\t Escreva o nome do jogador1");
    scanf("%s",jogador1);
    printf("\a");
    printf("\n\t Escreva o nome do jogador2:");
    scanf("%s",jogador2);
    printf("\n As regras sao simples...\n");
    printf("Ao final da partida, o jogador que tiver mais pecas vence\n");
    printf("\n 'x'  'o' ");
    setclr(31);
    sleep(1);
    printf("\a");
    printf("\n\n Qual o simbolo do jogador1:");
    scanf(" %c",&A);
    printf("\a");
    printf("\n QUal o simbolo do jogador2: ");
    scanf(" %c",&B);
    if(A==B)
    {
        printf("  Voces escolheram o mesmo simbolo ");
        goto intro;
    }
    printf("\a");
    printf("\n A partida ira comecar agora!");
    char tick=A;
    char TICK=B;
    tabuleiro[0][0]=B;tabuleiro[0][2]=B;tabuleiro[0][4]=B;tabuleiro[0][6]=B;
    tabuleiro[1][1]=B;tabuleiro[1][3]=B;tabuleiro[1][5]=B;tabuleiro[1][7]=B;
    tabuleiro[2][0]=B;tabuleiro[2][2]=B;tabuleiro[2][4]=B;tabuleiro[2][6]=B;
    tabuleiro[5][1]=A;tabuleiro[5][3]=A;tabuleiro[5][5]=A;tabuleiro[5][7]=A;
    tabuleiro[6][0]=A;tabuleiro[6][2]=A;tabuleiro[6][4]=A;tabuleiro[6][6]=A;
    tabuleiro[7][1]=A;tabuleiro[7][3]=A;tabuleiro[7][5]=A;tabuleiro[7][7]=A;

    start:
    display(tabuleiro);

    setclr(34);
    printf("\a");
    printf("\n Turno do jogador1 (%c)",A);
    printf("\n Escreva o posicao em que voce quer mover sua peca:");
    scanf("%s",pos);
    printf("\n");
    if(pos[0]== 'A')
        x=0;
    else if(pos[0]== 'B')
        x=1;
    else if(pos[0]== 'C')
        x=2;
    else if(pos[0]== 'D')
        x=3;
    else if(pos[0]== 'E')
        x=4;
    else if(pos[0]== 'F')
        x=5;
    else if(pos[0]== 'G')
        x=6;
    else if(pos[0]== 'H')
        x=7;
    else
    {
        
        printf("jogada invalida, escreva novamente");
        goto start;
    }
    if(pos[1]== '1')
        y=0;
    else if(pos[1]== '2')
        y=1;
    else if(pos[1]== '3')
        y=2;
    else if(pos[1]== '4')
        y=3;
    else if(pos[1]== '5')
        y=4;
    else if(pos[1]== '6')
        y=5;
    else if(pos[1]== '7')
        y=6;
    else if(pos[1]== '8')
        y=7;
    else
    {
        printf("jogada invalida, escreva novamente");
        goto start;
    }
    if(tabuleiro[y][x]!=A)
    {
        printf("jogada invalida, escreva novamente");
        goto start;
    }
    printf("\a");
    printf("Qual direcao?\n1-diagonal superior esquerda\n2-diagonal superior direita\n3-diagonal inferior esquerda\n4-diagonal inferior direita\n");
    scanf(" %d",&dir);
    A=tick;
    B=TICK;
    setclr(39);

    if(dir == 1)
    {
        if(x==0 || y==0)
        {
            printf("jogada invalida");
            goto start;
        }
        if(tabuleiro[y-1][x-1]==A)
        {
            printf("jogada invalida");
            goto start;
        }
        if(tabuleiro[y - 1][x - 1]==' ')
        {
            tabuleiro[y][x]=' ';
            tabuleiro[--y][--x]=A;
            goto feito1;
        }
        if(tabuleiro[y - 1][x - 1]==B)
        {
            if(x<=1)
            {
                printf("jogada invalida, peca obstruindo");
                goto start;
            }
            if(tabuleiro[y - 2][x - 2]!=' ')
            {
                printf("jogada invalida, peca obstruindo");
                goto start;
            }
            else
            {
                tabuleiro[y][x]=' ';
                tabuleiro[y - 1][x - 1]=' ';
                y-=2;x-=2;
                tabuleiro[y][x]=A;
                goto feito1;
            }
        }
    }
    if(dir==2)
    {
        if(x==7 || y==0)
        {
            printf("jogada invalida");
            goto start;
        }
        if(tabuleiro[y - 1][x + 1]==A)
        {
            printf("jogada invalida");
            goto start;
        }
        if(tabuleiro[y - 1][x + 1]==' ')
        {
            tabuleiro[y][x]=' ';
            tabuleiro[--y][++x]=A;
            goto feito1;
        }
        if(tabuleiro[y - 1][x + 1]==B)
        {
            if(x>=6)
            {
                printf("jogada invalida, peca obstruindo");
                goto start;
            }
            if(board[y - 2][x + 2]!=' ')
            {
                printf("jogada invalida, peca obstruindo");
                goto start;
            }
            else
            {
                tabuleiro[y][x]=' ';
                tabuleiro[y - 1][x + 1]=' ';
                y-=2;x+=2;
                tabuleiro[y][x]=A;
                goto feito1;
            }
        }
    }
    if(dir==3)
    {
        if(x==0 || y==7)
        {
            printf("jogada invalida");
            goto start;
        }
        if(tabuleiro[y + 1][x - 1]==A)
        {
            printf("jogada invalida");
            goto start;
        }
        if(tabuleiro[y + 1][x - 1]==' ')
        {
            tabuleiro[y][x]=' ';
            tabuleiro[++y][--x]=A;
            goto feito1;
        }
        if(tabuleiro[y + 1][x - 1]==B)
        {
            if(x<=1)
            {
                printf("jogada invalida, peca obstruindo");
                goto start;
            }
            if(tabuleiro[y + 2][x - 2]!=' ')
            {
                printf("jogada invalida, peca obstruindo");
                goto start;
            }
            else
            {
                tabuleiro[y][x]=' ';
                tabuleiro[y + 1][x - 1]=' ';
                y+=2;x-=2;
                tabuleiro[y][x]=A;
                goto feito1;
            }
        }
    }
    if(dir==4)
    {
        if(x==7 || y==7)
        {
            printf("jogada invalida");
            goto start;
        }
        if(tabuleiro[y + 1][x + 1]==A)
        {
            printf("jogada invalida");
            goto start;
        }
        if(tabuleiro[y + 1][x + 1]==' ')
        {
            tabuleiro[y][x]=' ';
            tabuleiro[++y][++x]=A;
            goto feito1;
        }
        if(tabuleiro[y + 1][x + 1]==B)
        {
            if(x>=6)
            {
                printf("jogada invalida, peca obstruindo");
                goto start;
            }
            if(board[y + 2][x + 2]!=' ')
            {
                printf("jogada invalida, peca obstruindo");
                goto start;
            }
            else
            {
                tabuleiro[y][x]=' ';
                tabuleiro[y + 1][x + 1]=' ';
                y+=2;x+=2;
                tabuleiro[y][x]=A;
                goto feito1;
            }
        }
    }
    feito1:
        display(tabuleiro);
        pla=0;opo=0;
        A=tick;
        B=TICK;
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(tabuleiro[i][j]==A)
                    pla+=5;
            }
        }
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(tabuleiro[i][j]==B)
                    opo+=5;
            }
        }

        printf("\n\t\t\t\t Pontuacao Atual:");
        printf("\n\t\t\t\t%s = %d",jogador1,pla);
        printf("\n\t\t\t\t%s = %d",jogador2,opo);
        if(pla==0 || opo==0)
            goto end;
    printf("\n");
    setclr(34);
    printf("turno do jogador2 (%c)",B);
    again:
        if(limite==15)
        {
            printf("\n O jogador2 esta em narnia");
            limite=0;
            goto start;
        }
        if(yolo==15)
        {
            for(i=0;i<8;i++)
            {
                for(j=0;j<8;j++)
                {
                    if(tabuleiro[i][j]==B);
                    {
                        y=i;
                        x=j;
                    }
                }
            }
            yolo=0;
            limite++;
        }
        else
        {
            y = rand()%8;
            x = rand()%8;
        }
        if(tabuleiro[y][x]!=B)
            goto again;
            dir=(rand()%4)+1;
        if(tabuleiro[y - 1][x - 1]==A && x>1 && y>1)
            dir=1;
        if(tabuleiro[y - 1][x + 1]==A && x<6 && y>1)
            dir=2;
        if tabuleiro[y + 1][x - 1]==A && x>1 && y<6)
            dir=3;
        if(tabuleiro[y + 1][x + 1]==A && x<6 && y<6)
            dir=4;
        A=tick;
        B=TICK;

        if(dir==1)
        {
            if(x==0 || y==0)
            {
                yolo++;
                sleep(1);
                goto again;
            }
            if(tabuleiro[y - 1][x - 1]==B)
            {
                yolo++;
                sleep(1);
                goto again;
            }
            if(tabuleiro[y - 1][x - 1]==' ')
            {
                tabuleiro[y][x]=' ';
                tabuleiro[--y][--x]=B;
                goto feito2;
            }
            if(tabuleiro[y - 1][x - 1]==A)
            {
                if(x>=1)
                {
                    yolo++;
                    sleep(1);
                    goto again;
                }
                if(tabuleiro[y - 2][x - 2]!=' ')
                {
                    yolo++;
                    sleep(1);
                    goto again;
                }
                else
                {
                    tabuleiro[y][x]=' ';
                    tabuleiro[y - 1][x - 1]=' ';
                    y-=2;x-=2;
                    tabuleiro[y][x]=B;
                    goto feito2;
                }
            }
        }
        if(dir==2)
        {
            if(x==7 || y==0)
            {
                yolo++;
                sleep(1);
                goto again;
            }
            if(tabuleiro[y - 1][x + 1]==B)
            {
                yolo++;
                sleep(1);
                goto again;
            }
            if(tabuleiro[y - 1][x + 1]==' ')
            {
                tabuleiro[y][x]=' ';
                tabuleiro[--y][++x]=B;
                goto feito2;
            }
            if(tabuleiro[y - 1][x + 1]==A)
            {
                if(x>=6)
                {
                    yolo++;
                    sleep(1);
                    goto again;
                }
                if(tabuleiro[y - 2][x + 2]!=' ')
                {
                    yolo++;
                    sleep(1);
                    goto again;
                }
                else
                {
                    tabuleiro[y][x]=' ';
                    tabuleiro[y - 1][x + 1]=' ';
                    y-=2;x+=2;
                    tabuleiro[y][x]=B;
                    goto feito2;
                }
            }
        }
        if(dir==3)
        {
            if(x==0 || y==7)
            {
                yolo++;
                sleep(1);
                goto again;
            }
            if(tabuleiro[y + 1][x - 1]==B)
            {
                yolo++;
                sleep(1);
                goto again;
            }
            if(tabuleiro[y + 1][x - 1]==' ')
            {
                tabuleiro[y][x]=' ';
                tabuleiro[++y][--x]=B;
                goto feito2;
            }
            if(tabuleiro[y + 1][x - 1]==A)
            {
                if(x>=1)
                {
                    yolo++;
                    sleep(1);
                    goto again;
                }
                if(tabuleiro[y + 2][x - 2]!=' ')
                {
                    yolo++;
                    sleep(1);
                    goto again;
                }
                else
                {
                    tabuleiro[y][x]=' ';
                    tabuleiro[y + 1][x - 1]=' ';
                    y+=2;x-=2;
                    tabuleiro[y][x]=B;
                    goto feito2;
                }
            }
        }
        if(dir==4)
        {
            if(x==7 || y==7)
            {
                yolo++;
                sleep(1);
                goto again;
            }
            if(tabuleiro[y + 1][x + 1]==B)
            {
                yolo++;
                sleep(1);
                goto again;
            }
            if(tabuleiro[y + 1][x + 1]==' ')
            {
                tabuleiro[y][x]=' ';
                tabuleiro[++y][++x]=B;
                goto done2;
            }
            if(tabuleiro[y + 1][x + 1]==A)
            {
                if(x>=6)
                {
                    yolo++;
                    sleep(1);
                    goto again;
                }
                if(tabuleiro[y + 2][x + 2]!=' ')
                {
                    yolo++;
                    sleep(1);
                    goto again;
                }
                else
                {
                    tabuleiro[y][x]=' ';
                    tabuleiro[y + 1][x + 1]=' ';
                    y+=2;x+=2;
                    tabuleiro[y][x]=B;
                    goto feito2;
                }
            }
        }
    feito2:
        display(feito2);

        pla=0;
        opo=0;
        A=tick;
        B=TICK;
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(tabuleiro[i][j]==A)
                    pla+=5;
            }
        }
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(tabuleiro[i][j]==B)
                    opp+=5;
            }
        }
        printf("\n\t\t\t\tCurrent scores:");
        printf("\n\t\t\t\t%s = %d",jogador1,pla);
        printf("\n\t\t\t\t%s = %d",jogador2,opo);
        if(pla==0 || opo==0)

            goto end;
        else
            goto start;
    end:
        setclr(40);
        if(pla>opo)
        {
            sleep(1);
            printf("\n\n");
            printf("\n%s's score:%d",jogador1,pla);
            printf("\n%s's score:%d",jogador2,opo);
            printf("\n%s Ganhou o jogo",jogador1);
            sleep(1);
            system("cls");
            if(pla>pontuacao)
            {
                sleep(1);
                pontuacao=pla;
                strcpy(nhigh,jogador1);
                setclr(34);
                printf("\n Novo recorde");
                f=fopen("F:\\pontuacao.txt","w");
                fprintf(f,"\n %s = %d",nhigh,pontuacao);
                fclose(f);
                printf("\n Maior pontuacao:\n%s = %d",nhigh,pontuacao);
            }
        }
        if(pla<opo)
        {
            sleep(1);
            printf("\n\n");
            printf("\n%s's pontos:%d",jogador1,pla);
            printf("\n%s's pontos:%d",jogador2,opo);
            printf("\n%s Ganhou a partida",jogador2);
            sleep(1);

            system("cls");
            if(opp>pontuacao)
            {
                sleep(1);
                pontuacao=opo;
                strcpy(nhigh,jogador2);
                setclr(34);

                printf("\nNovo Recorde");
                f=fopen("F:\\pontuacao.txt","w");
                fprintf(f,"\n %s = %d",nhigh,pontuacao);
                fclose(f);
                printf("\nMaior pontuacao:\n%s = %d",nhigh,pontuacao);
            }
        }
        if(pla==opo)
        {
            sleep(1);
            printf("\n\n");
            printf("\n%s's pontos:%d",jogador1,pla);
            printf("\n%s's pontos:%d",jogador2,opo);
            printf("\nEmapate!");
            sleep(1);

            system("cls");
            if(pla>pontuacao)
            {
                sleep(1);
                pontuacao=pla;
                strcpy(nhigh,jogador1);
                setclr(34);


                f=fopen("F:\\pontuacao.txt","w");
                fprintf(f,"\n %s = %d",nhigh,pontuacao);
                fclose(f);
                printf("\nRecorde:\n%s = %d",nhigh,pontuacao);
            }
            if(opo>pontuacao)
            {
                sleep(1);
                pontuacao=opo;
                strcpy(nhigh,jogador2);
                setclr(34);


                f=fopen("F:\\pontuacao.txt","w");
                fprintf(f,"\n %s = %d",nhigh,pontuacao);
                fclose(f);
                printf("\nRecorde:\n%s = %d",nhigh,pontuacao);
            }
        }

    getch();
    return 0;
}


