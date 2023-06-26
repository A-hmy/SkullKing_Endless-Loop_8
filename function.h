#ifndef FUNCTION_H
#define FUNCTION_H
#include<QString>
#include"player.h"
void StartGame() ;
void Dealing(int NumberOfRound);
void File_WriteOnly(QString FileName,Player player);
void File_Read(QString FileName);
#endif // FUNCTION_H
