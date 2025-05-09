/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:02:00 by acharik           #+#    #+#             */
/*   Updated: 2025/05/03 21:48:03 by mel-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSING_H
# define MAP_PARSING_H

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

/*
	this struct have some membres releated
	of data in the map
*/
typedef struct s_data_par
{
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	int		ceiling_color;
	int		floor_color;
	double	tita;
	char	**maze;
	int		nbr_lin;
	int		x_player;
	int		y_player;
}			t_data_par;

/*
	This struct have some index membres for check numbers of
	this elements in the file
*/
typedef struct s_index
{
	int		n_derc;
	int		n_color;
	int		maze_index;
	int		new_line;
}			t_index;

/*  check and get data form file.cub*/
void		ft_parsing(int argc, char **argv, t_data_par *parsing);

/* read map and ansert data to t_data_par  */
void		read_map(char *file, t_data_par *parsing);

/* check the file is exist or not */
int			check_file_argument(char **argv, int argc);

/* get nbr of lines in the fd (cub utils) */
int			get_nbr_line(int fd);

/* print the data parssing */
void		print_data(t_data_par *parsing);

/* check the coloe and convet it to int varialble*/
void		get_color_values(t_data_par *parsing, char *line, t_index *index);

char		*ft_itoa(int n);
void		ft_free(char **leaks);
void		print_tab(char **tab);

//!-----------Errors-----------------
void		error_line(t_data_par *ft_parsing);
void		error_map(t_data_par *ft_parsing);
void		error_player(void);
void		error_color(t_data_par *ft_parsing);
/*!-----------Texture-----------------*/
/* get texture path and add it to his varible in parssing */
void		texture_value(t_data_par *parsing, char *line, int *nbr);
void		check_textures(t_data_par *parsing, t_index *index, char *line);
char		*get_path_check(char *line, char *ser);
// void check_texture(t_data_par *parsing,int n_derc , int n_color);
//!------------tools--------------------
/* check_possiblt of textures NO SO WE EA   */
int			check_possiblty_tex(char *line);
/* check possiblty of this char (1 0 p ' ')*/
int			check_possiblty(char c);
/* initialise the data members of t_data_par */
void		init(t_data_par *parsing);

/* check line if any zero in it */
int			true_line(char *str);
void		free_function(char **str);

//!-----------------get_next--------
size_t		ft_strlen(const char *str);
// char		*ft_strdup(char *src);
int			check_fun(char *s);
// int		check_back_s(char *s);
char		*d_line(char *line);
char		*get_next_line(int fd);
char		*ft_substr(char const *s, unsigned int start, size_t len);

//!------------lib---------------
int			ft_atoi(const char *nbr);
void		*ft_calloc(size_t len, size_t size);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strjjoin(char *s1, char *s2);
void		check_maze_player(t_data_par *parsing);
void		around_ps(t_data_par *parsing, int i, int index);
int			around_zero(t_data_par *parsing, int index, char *line, int i);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *string);
char		*ft_strjoin2(char *strr, char *buff);
char		*ft_strchr2(char *str, int c);
size_t		ft_strlen(const char *str);
int			check_line2(char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*get_next_line(int fd);

#endif
