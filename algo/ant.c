/*
** ant.c for ant in /home/duhieu_b/CPE/CPE_2015_lemin/algo
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sat Apr  2 13:24:27 2016 benjamin duhieu
** Last update Thu Apr  7 19:41:06 2016 benjamin duhieu
*/

int		chk_id(t_tube *new_elem, t_tube *tube)
{
  t_tube	*elem;

  elem = tube;
  while (elem->next)
    {
      if (elem->id == new_elem->room->id)
	return (1);
      elem = elem->next;
    }
  return (0);
}

int		all_ways(t_tube *tube, t_tube *new_elem,
			 t_path **tmp , t_room *room)
{
  t_tube	*elem;
  t_tube	*tmp_tube;

  tmp_tube = room->tubes;
  if (chk_id(tmp_tube, tube))
    {
      free(new_elem);
      return (1);
    }
  if (new_elem->room->last)
    {
      /* if (!tmp->i) */
      /* 	{ */
      /* 	  tmp->i = new_elem->nb; */
      /* 	  tmp->tube = tube; */
      /* 	} */
      /* else */
      /* 	if (tmp->i > new_elem->nb) */
      /* 	  { */
      /* 	    tmp->i = new_elem->nb; */
      /* 	    tmp->tube = tube; */
      /* 	  } */
      tmp[tmp->way]->tube = tube;
      tmp[tmp->way]->i = new_elem->nb;
      tmp->way++;
      if (!(tmp = my_realloc_path(tmp, tmp->way + 2)))
	return (2);
      if (!(tmp[tmp->way] = malloc(sizeof(t_path))))
	return (2);
      tmp[tmp->way + 1] = NULL;
      free(new_elem);
      return (1);
    }
  if (!tmp_tube->next)
    {
      free(new_elem);
      return (1);
    }
  while (tmp_tube)
    {
      if (tmp_tube->room)
	{
	  if (!(elem = malloc(sizeof(t_tube))))
	    return (2);
	  new_elem->next = elem;
	  elem->room = tmp_tube->room;
	  elem->nb = new_elem->nb + 1;
	  elem->id = tmp_tube->room->id;
	  elem->next = NULL;
	  if ((all_ways(tube, elem, tmp, room)) == 2)
	    return (2);
	}
      tmp_tube = tmp_tube->next;
    }
  free(new_elem);
  return (0);
}

int		shorts_path(t_path **way, int nb_path)
{
  int		i;
  int		j;
  int		tmp;
  int		place;

  i = -1;
  while (++i < nb_path)
    {
      j = -1 + i;
      while (way && way[++j])
	{
	  if (j == 0)
	    {
	      tmp = way[j]->i;
	      place = j;
	    }
	  else
	    {
	      if (tmp > way[j]->i)
		{
		  tmp = way[j]->i;
		  place = j;
		}
	    }
	}
    }
}

int		path(t_room *room, t_path **way, int nb_path)
{
  t_tube	*elem;
  t_tube	*new_elem;
  t_room	*tmp_room;

  if (!(way[0] = malloc(sizeof(t_path))))
    return (my_put_error(MALLOC_ERR), 1);
  way[1] = NULL;
  if (!(elem = malloc(sizeof(t_tube))))
    return (my_put_error(MALLOC_ERR), 1);
  elem->room = room->next;
  new_elem = elem;
  new_elem->nb = 1;
  new_elem->id = room->next->id;
  new_elem->next = NULL;
  tmp_room = root->next;
  way[0]->i = 0;
  way[0]->way = 0;
  if ((all_ways(elem, new_elem, way, tmp_room)) == 2)
    return (my_put_error(MALLOC_ERR), 1);
  if (!(shorts_path(way, nb_path)))
    return (1);
  return (0);
}

/* t_path		**kill_path(t_room *room) */
/* { */

/* } */

int		path_ant(t_room	*room)
{
  t_room	*elem;
  int		i;

  elem = room->next;
  i = 1;
  while (elem->tubes->next != NULL)
    {
      i++;
      elem->tubes = elem->tubes->next;
    }
  return (i);
}

int	ant_on_the_way(t_ant *ant)
{
  t_ant	*elem;

  elem = ant;
  while (elem->next != NULL)
    {
      if (!elem->finish)
	return (1);
      elem = elem->next;
    }
  return (0);
}

/* int		nb_strokes(t_path **way, t_ant *ant, int a) */
/* { */
/*   int		i; */
/*   int		ret; */

/*   ret = 0; */
/*   while (ant_on_the_way(ant) && ++ret) */
/*     { */
/*       elem = ant; */
/*       while (elem->next != NULL) */
/* 	{ */
/* 	  i = -1; */
/* 	  while (++i < a && elem->next != NULL) */
/* 	    { */
/* 	      if (!elem->finish && !elem->way[i]->room->next->ants) */
/* 		{ */
/* 		  elem->way[i]->room->ants = 0; */
/* 		  if (!elem->way->room->next->last) */
/* 		    elem->way->room->next->ants = 1; */
/* 		  else */
/* 		    elem->finish = 1; */
/* 		} */
/* 	      elem = elem->next; */
/* 	    } */
/* 	} */
/*     } */
/*   return (ret); */
/* } */

/* int		count_way(t_path **way, t_ant *ant, int nb_path) */
/* { */
/*   int		i; */
/*   int		res; */
/*   int		dir; */
/*   int		ret; */

/*   i = 0; */
/*   dir = 0; */
/*   while (++i <= nb_path) */
/*     { */
/*       if (i == 1) */
/* 	{ */
/* 	  dir = nb_strokes(way, ant, i); */
/* 	  ret = i; */
/* 	} */
/*       else */
/* 	{ */
/* 	  res = nb_strokes(way, ant, i); */
/* 	  if (dir > res) */
/* 	    { */
/* 	      dir = res; */
/* 	      ret = i; */
/* 	    } */
/* 	} */
/*     } */
/*   return (ret); */
/* } */

/* void	start_ant(t_path *way, t_ant *ant) */
/* { */
/*   t_ant	*elem; */

/*   elem = ant; */
/*   while (elem->next != NULL) */
/*     { */
/*       elem->way = way; */
/*       elem = elem->next; */
/*     } */
/*   while (ant_on_the_way(ant)) */
/*     { */
/*       elem = ant; */
/*       while (elem->next != NULL) */
/* 	{ */
/* 	  if (!elem->finish && !elem->way->tube->next->room->ants) */
/* 	    { */
/* 	      elem->way->tube->room->ants = 0; */
/* 	      if (!elem->way->tube>next->room->last) */
/* 		elem->way->tube->next->room->ants = 1; */
/* 	      else */
/* 		elem->finish = 1; */
/* 	    } */
/* 	  elem = elem->next; */
/* 	} */
/*     } */
/* } */

void	multi_path(t_path **way, t_ant *ant, int nb_path)
{
  t_ant	*elem;
  int	a;

  /* a = count_way(way, nb_path); */
  elem = ant;
  while (elem->next != NULL)
    {
      elem->way = way;
      elem = elem->next;
    }
  while (ant_on_the_way(ant))
    {
      elem = ant;
      while (elem->next != NULL)
	{
	  i = -1;
	  while (++i < a && elem->next != NULL)
	    {
	      if (!elem->finish &&
		  !elem->way[i]->tube->next->room->ants)
		{
		  elem->way[i]->tube->room->ants = 0;
		  if (!elem->way[i]->tube->next->room->last)
		    elem->way[i]->tube->room->ants = 1;
		  else
		    elem->finish = 1;
		}
	      elem = elem->next;
	    }
	}
    }
}

t_ant	*list_ant(t_path **way, int nb)
{
  t_ant	*first;
  t_ant	*elem;
  int	i;

  if (!(first = malloc(sizeof(t_ant))))
    return (NULL);
  first->next = NULL;
  elem = first;
  i = -1;
  while (++i < nb)
    {
      elem->way = way;
      elem->finish = 0;
      elem->next = NULL;
      if (!(elem->next = malloc(sizeof(t_ant))))
	return (NULL);
      elem = elem->next;
    }
  elem->next = NULL;
  return (first);
}

int		start(t_room *room, t_ant *ant, int nb)
{
  t_path	**way;
  int		nb_path;

  nb_path = path_ant(room);
  if (!(way = malloc(sizeof(t_path *) * 2)))
    return (1);
  way[1] = NULL;
  /* if (!room->tubes->next) */
  /*   { */
  if ((path(room, way, nb_path)))
    return (1);
  if (!(ant = list_ant(way, nb)))
    return (1);
  start_ant(way, ant);
  return (0);
    /* } */
  /* else */
  /*   { */
  /*     if (!(way = kill_path(room))) */
  /* 	return (1); */
  /*     if (!(ant = list_ant(way, nb_path))) */
  /* 	return (1); */
  /*     multi_path(way, ant, nb_path); */
  /*     return (0); */
  /*   } */
  /* return (0); */
}

int		main()
{
  t_room	room;
  t_ant		ant;

  start(&room, &ant);
  return (0);
}
