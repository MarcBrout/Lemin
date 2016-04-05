/*
** ant.c for ant in /home/duhieu_b/CPE/CPE_2015_lemin/algo
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sat Apr  2 13:24:27 2016 benjamin duhieu
** Last update Tue Apr  5 14:11:21 2016 benjamin duhieu
*/

int		chk_id(t_room *room, t_room *new_elem)
{
  t_room	*elem;

  elem = root->next;


}

int		all_ways(t_tube *tube, t_tube *new_elem,
			 t_path *tmp , t_room *room)
{
  t_tube	*elem;
  t_tube	*tmp_tube;

  tmp_tube = room->tubes;
  if (chk_id(room, new_elem))
    {
      free(new_elem);
      return (1);
    }
  if (new_elem->room->last)
    {
      if (!tmp[0]->i)
	{
	  tmp[0]->i = new_elem->nb;
	  tmp[0]->tube = tube;
	}
      else
	if (tmp[0]->i > new_elem->nb)
	  {
	    tmp[0]->i = new_elem->nb;
	    tmp[0]->tube = tube;
	  }
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
	  elem->next = NULL;
	  if ((all_ways(tube, elem, tmp, room)) == 2)
	    return (2);
	}
      tmp_tube = tmp_tube->next;
    }
  free(new_elem);
  return (0);
}

t_path		*short_path(t_room *room)
{
  t_tube	*elem;
  t_tube	*new_elem;
  t_room	*tmp;
  t_path	**tmp;
  int		i;

  if (!(tmp[0] = malloc(sizeof(t_path))))
    return (1);
  tmp[1] = NULL;
  if (!(elem = malloc(sizeof(t_path))))
    return (1);
  elem->room = room->next;
  new_elem = elem;
  new_elem->nb = 1;
  new_elem->next = NULL;
  tmp = root->next;
  tmp[0]->i = 0;
  short_way(elem, new_elem, tmp[0], tmp);
}

t_path		**kill_path(t_room *room)
{

}

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

int		nb_strokes(t_path **way, t_ant *ant, int a)
{
  int		i;
  int		ret;

  ret = 0;
  while (ant_on_the_way(ant) && ++ret)
    {
      elem = ant;
      while (elem->next != NULL)
	{
	  i = -1;
	  while (++i < a && elem->next != NULL)
	    {
	      if (!elem->finish && !elem->way[i]->room->next->ants)
		{
		  elem->way[i]->room->ants = 0;
		  if (!elem->way->room->next->last)
		    elem->way->room->next->ants = 1;
		  else
		    elem->finish = 1;
		}
	      elem = elem->next;
	    }
	}
    }
  return (ret);
}

int		count_way(t_path **way, t_ant *ant, int nb_path)
{
  int		i;
  int		res;
  int		dir;
  int		ret;

  i = 0;
  dir = 0;
  while (++i <= nb_path)
    {
      if (i == 0)
	{
	  dir = nb_strokes(way, ant, i);
	  ret = i;
	}
      else
	{
	  res = nb_strokes(way, ant, i);
	  if (dir > res)
	    {
	      dir = res;
	      ret = i;
	    }
	}
    }
  return (ret);
}

void	start_ant(t_path *way, t_ant *ant)
{
  t_ant	*elem;

  elem = ant->next;
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
	  if (!elem->finish && !elem->way->room->next->ants)
	    {
	      elem->way->room->ants = 0;
	      if (!elem->way->room->next->last)
		elem->way->room->next->pass = 1;
	      else
		elem->finish = 1;
	    }
	  elem = elem->next;
	}
    }
}

void	multi_path(t_path **way, t_ant *ant, int nb_path)
{
  t_ant	*elem;
  int	a;

  a = count_way(way, nb_path);
  while (ant_on_the_way(ant))
    {
      elem = ant;
      while (elem->next != NULL)
	{
	  i = -1;
	  while (++i < a && elem->next != NULL)
	    {
	      if (!elem->finish && !elem->way[i]->room->next->ants)
		{
		  elem->way[i]->room->ants = 0;
		  if (!elem->way->room->next->last)
		    elem->way->room->next->ants = 1;
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
  if (!(way = malloc(sizeof(t_path) * (nb_path + 1))))
    return (1);
  way[nb_path] = NULL;
  if (!room->tubes->next)
    {
      if (!(way[0] = short_path(room)))
	return (1);
      if (!(ant = list_ant(way, nb)))
	return (1);
      start_ant(way[0], ant);
      return (0);
    }
  else
    {
      if (!(way = kill_path(room)))
	return (1);
      if (!(ant = list_ant(way, nb_path)))
	return (1);
      multi_path(way, ant, nb_path);
      return (0);
    }
  return (0);
}

int		main()
{
  t_room	room;
  t_ant		ant;

  start(&room, &ant);
  return (0);
}
