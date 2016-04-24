/*
** tool2.c for bonus in /home/theis_p/git/CPE/CPE_2015_Lemin/Bonus/src/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Sat Apr 23 17:19:12 2016 THEIS Paul
** Last update Sun Apr 24 16:58:01 2016 benjamin duhieu
*/

#include "main.h"

bool		is_num(char c)
{
  return ((c >= '0' && c <= '9') ? (TRUE) : (FALSE));
}

bool		is_alpha(char c)
{
  return (((c >= 'a' && c <= 'z') ||
	   (c >= 'A' && c <= 'Z')) ? (TRUE) : (FALSE));
}
