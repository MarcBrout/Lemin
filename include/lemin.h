/*
** lemin.h for lemin in ~/RENDU/CPE/CPE_2015_lemin
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Apr  1 15:55:58 2016 marc brout
** Last update Tue Apr 12 17:10:23 2016 marc brout
*/

#ifndef LEMIN_H_
# define LEMIN_H_

# define UNUSED __attribute__((__unused__))
# define MALLOC_ERR "Can't perform malloc.\n"
# define EMPTY_FOLDER "File is empty.\n"
# define WRONG_ANTS "Positive number of ants expected.\n"
# define SAME_ROOM "Rooms are sharing the same coordinates\n"
# define SAME_START_END "Error, same start and end room\n."
# define MISSING_START "Missing start label.\n"
# define TOO_MUCH_END "Too much end rooms.\n"
# define TOO_MUCH_START "Too much start rooms.\n"
# define MISSING_END "Missing end label.\n"
# define MISSING_END_ROOM "Missing end room.\n"
# define MISSING_ROOM "At least 2 rooms are needed.\n"
# define EXISTING_ROOM " existing, skipping it.\n"
# define WRONG_ROOM " not correct, skipping it.\n"
# define WRONG_TUBE "Tube line incorrect, skipping it.\n"
# define SAME_LINK "Can't link a room on itself, skipping line.\n"
# define ROOM_TROUBLE "Trouble while loading rooms, aborting.\n"
# define MISSING_TUBES "One valid path must exists.\n"
# define INVALID_ROOM " Does not exist, skipping tube creation.\n"
# define NO_PATH "No path available, exiting.\n"
# define BAD_FORMAT "Bad line format, skipping it.\n"

typedef struct		s_room
{
  char			*name;
  int			id;
  char			pass;
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
  int			branch;
  struct s_tube		*next;
}			t_tube;

typedef struct		s_data
{
  int			ants;
  int			end_ants;
  t_room		*rooms;
}			t_data;

/* typedef	struct		s_way */
/* { */
/*   t_room		*room; */
/*   struct s_way		*next; */
/* }			t_way; */

typedef	struct		s_larg
{
  int			count;
  char			valid;
  t_tube		*pile;
  struct s_larg		*next;
}			t_larg;

typedef struct		s_path
{
  char			pass;
  t_tube		*tube;
  int			way;
  int			branch;
  int			i;
}			t_path;

typedef	struct		s_tree
{
  int			i;
  int			j;
  int			path;
  char			bool;
  int			branch;
  int			tmp;
  int			place;
}			t_tree;

typedef struct		s_ant
{
  t_path		**way;
  char			finish;
  int			num;
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

/*
** algo.c
*/

int			start(t_room *, t_ant *, int);

/*
** all_path.c
*/

int			all_ways(t_tube *, t_tube *,
				 t_path ***, t_tube *);
int			path(t_room *, t_path **, int);

/*
** chk_path.c
*/

int			chk_id(t_tube *, t_tube *);
int			chk_path(t_tube *, t_tube *,
				 t_path ***);
int			new_path(t_tube *, t_tube *,
				 t_path ***, t_tube *);
int			other_chk(t_tube *, t_tube *,
				  t_tube *);
t_path			**my_realloc_path(t_path **, int);

/*
** short_path.c
*/

int			first(int, int *, int, t_path *);
int			same_way(t_path *, t_path **way, int);
int			shorts_path(t_path ***, int);
int			swap(int, int *, t_path **);

/*
** ant.c
*/

int			path_ant(t_room *);
int			ant_on_the_way(t_ant *);
t_ant			*list_ant(t_path **way, int);
void			aff_ant(t_ant *, int);
void			start_ant(t_ant *, int);

/*
** solve_one_path.c
*/

t_tube			*remove_from_the_pile(t_tube *root);
int			add_one_to_the_pile(t_tube *root,
					    t_tube *tube);
int			add_all_to_the_pile(t_tube *root,
					    t_tube *tubes);
int			solve_one_path(t_room *root);
t_room			*find_first_room(t_room *root);

/*
** checks.c
*/

int			check_first_last(t_room *root);
int			check_room_position(t_room *root);
int			check_existing_room(t_room *root,
					    t_room *test,
					    char *name);

/*
** graph.c
*/

int			set_root(t_data *data);
int			add_tube(t_room *base, t_room *target);
t_room			*search_room(t_room *root, char *room);
int			link_rooms(t_room *root, char *room1,
				   char *room2);
int			prepare_rooms(char *str, t_room *root);

/*
** get_graph.c
*/

char			*my_getfirst_name(char *str, int *i, char c);
int			set_new_x_y(t_room *ref, char *str);
int			get_one_room(t_room *root, t_room *ref,
				     char *next);
int			get_this_line(t_data *data, char *next,
				      t_room *ref, char *line);
int			get_all(t_data *data);

/*
** parsing.c
*/

int			get_ants(t_data *data);
int			count_words(char *str);
int			init_root(t_data *data);
int			parse_input(t_data *data);

/*
** free_pile.c
*/

void			free_tubes(t_tube *tubes);
void			free_graph(t_room *root);
void			free_pile(t_tube *root);

#endif /* !LEMIN_H_ */
