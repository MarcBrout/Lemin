/*
** str.h for minishell in /home/theis_p/git/PSU/PSU_2015_minishell2/inc/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Mar 30 20:03:42 2016 THEIS Paul
** Last update Wed Apr 20 18:45:55 2016 THEIS Paul
*/

#ifndef STR_H_
# define STR_H_

/*
** String opttions in str.c
*/

int	my_strlen(char *);
char    *my_strdup(char *);
char    *my_strcat(char *, char *);
char    *my_strcpy(char *, char *);
int     my_strncmp(char *, char *, int);

/*
** String opttions in str2.c
*/

char	*my_strndup (const char *, size_t);
char	*finder(char **, char *);
char	*remover(char *, char *);
char	*my_strset(size_t, char);
char	*my_char_to_string(char);

/*
** String opttions in str3.c
*/

int	count_line(char *);
void	drop_char(char *str, int i);
char	*my_strncpy(char *dest, char *src, int n);

/*
** String opttions in str4.c
*/

int	my_char_pos(char *, char, bool);
char	*my_strcut(char const *, size_t, size_t);
int	my_charcmp(char, char *);
char	*my_strjoin(char *, char *);
char	*my_strtrim(char *, char);

/*
** String opttions in str5.c
*/

char	*epur_str(char *str);
char	*my_strchr(char *, char);
bool	is_char_space(char);
int	my_getnbr(char *);

#endif /* !STR_H_ */
