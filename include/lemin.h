/*
** lemin.h for lemin in ~/RENDU/CPE/CPE_2015_lemin
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Apr  1 15:55:58 2016 marc brout
<<<<<<< HEAD
** Last update Thu Apr  7 19:41:05 2016 benjamin duhieu
=======
** Last update Thu Apr  7 12:07:03 2016 marc brout
>>>>>>> d9349f599f280533034c21b36eb393d3edde1a82
*/

#ifndef LEMIN_H_
# define LEMIN_H_

# define MALLOC_ERR "Can't perform malloc.\n"
# define EMPTY_FOLDER "File is empty.\n"
# define WRONG_ANTS "Positive number of ants expected.\n"
# define MISSING_START "Missing start label.\n"
# define MISSING_END "Missing end label.\n"
# define MISSING_END_ROOM "Missing end room.\n"
# define MISSING_ROOM "At least 2 rooms are needed.\n"
# define EXISTING_ROOM " existing, skipping it.\n"
# define WRONG_ROOM " not correct, skipping it.\n"
# define WRONG_TUBE "Tube line incorrect, skippint it.\n"
# define ROOM_TROUBLE "Trouble while loading rooms, aborting.\n"
# define MISSING_TUBES "One valid path must exists.\n"
# define INVALID_ROOM " Does not exist, skipping tube creation.\n"
# define NO_PATH "No path available, exiting.\n"
# define BAD_FORMAT "Bad line format, skipping it.\n"

typedef struct		s_room
{
  char			*name;
  int			id;
  char			first;
  char			last;
  char			ants;
  int			x;
  int			y;
  struct s_tube		*tubes;
  struct s_room		*next;
  struct s_room		*prev;
}			t_room;

typedef struct		s_tube
{
  t_room		*room;
  int			nb;
  int			id;
  struct s_tube		*next;
}			t_tube;

typedef struct		s_data
{
  int			ants;
  int			end_ants;
  t_room		*rooms;
}			t_data;

typedef struct		s_path
{
  char			pass;
  t_tube		*tube;
  int			way;
  int			i;
}			t_path;

typedef struct		s_ant
{
  t_path		**way;
  char			finish;
  struct s_ant		*next;
}			t_ant;

/*
** parsing/errors.c
*/

void			my_put_room_str(const char *file,
					const char *str);
int			my_put_file_noaccess(const char *file,
					     int err);
void			my_put_error(const char *str);
int			my_put_usage(char **av, int err);

/*
** parsing/my_bzero.c
*/

void			my_bzero(void *str, int size, char val);

/*
** parsing/parsing.c
*/

int			parse_input();

/*
** parsing/my_getnbr.c
*/

int			my_getnbrcst(const char *str);
int			my_getnbr_i(const char *str, int *i);

/*
** parsing/misc.c
*/

int			is_it_a_comment(char *str);
char			*epur_str(char *str);
int			get_next_str(char **str);

#endif /* !LEMIN_H_ */
