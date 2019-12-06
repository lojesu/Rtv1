/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:42:59 by reda-con          #+#    #+#             */
/*   Updated: 2019/10/10 13:51:49 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "SDL.h"
# include "libmath.h"
# include <stdint.h>

# define WIDTH 1080
# define HEIGHT 810
# define DIFFUSE 0.8
# define SPECULAR 0.4
# define T_MAX 500
# define RGB SDL_PIXELFORMAT_RGB888

typedef struct		s_cam
{
	t_pt	pos;
	t_pt	vpupleft;
	t_vec	vecdir;
	t_vec	rvec;
	t_vec	uvec;
	double	vp_height;
	double	vp_width;
	double	vp_dist;
	double	indentx;
	double	indenty;
}					t_cam;

typedef struct		s_ray
{
	t_pt	origin;
	t_vec	dir;
	double	t;
	t_vec	normal;
	size_t	truc;
}					t_ray;

typedef struct		s_sphere
{
	t_pt		c;
	double		r;
	uint32_t	color;
}					t_sphere;

typedef struct		s_plan
{
	t_pt			pt;
	t_vec			norme;
	uint32_t		color;
}					t_plan;

typedef struct		s_cone
{
	t_vec			dir;
	t_pt			tip;
	float			agl;
	uint32_t		color;
}					t_cone;

typedef struct		s_cylinder
{
	t_vec			dir;
	t_pt			pt;
	float			r;
	uint32_t		color;
}					t_cylinder;

typedef struct		s_light
{
	t_pt			pos;
	uint8_t			intensity;
}					t_light;

typedef	struct		s_color
{
	double			ambiant;
	double			diffuse;
	double			specular;
}					t_color;

typedef struct		s_objs
{
	t_sphere	*spheres;
	size_t		nb_spheres;
	t_plan		*plans;
	size_t		nb_plans;
	t_cone		*cones;
	size_t		nb_cones;
	t_cylinder	*cylinders;
	size_t		nb_cylinders;
	t_light		*light;
	size_t		nb_lights;
	t_color		color;
}					t_objs;

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Texture		*text;
	uint32_t		*pixels;
	SDL_Event		ev;
}					t_sdl;

/*
** init functions
*/
int					init_sdl(t_sdl *sdl);
t_pt				init_pt(double x, double y, double z);
t_vec				init_vec(double x, double y, double z);
t_ray				init_ray(t_pt origin, t_vec dir, double t);

/*
** function where i init my object
*/
t_sphere			init_sphere(t_pt c, double r, uint32_t color);
t_plan				init_plan(t_pt pt, t_vec norme, uint32_t color);
t_cone				init_cone(t_vec dir, t_pt tip, float agl, uint32_t color);
t_light				init_light(t_pt pos, uint32_t intensity);
t_cam				init_cam(t_pt pos, t_vec dir);
t_cylinder			init_cylinder(t_pt pt, t_vec dir, float r, uint32_t color);

/*
** parsing functions
*/
void				parsing(int argc, char **argv, t_cam *cam, t_objs *objs);
void				verif_camera(char *line, t_cam *cam);
/*
**verif_light
*/
void				verif_light(char *line, t_objs *objs);
void				verif_ambiant(char *line, t_objs *objs);
void				verif_diffuse(char *line, t_objs *objs);
void				verif_specular(char *line, t_objs *objs);
/*
** verif_objs
*/
void				verif_sphere(char *line, t_objs *objs);
void				verif_plan(char *line, t_objs *objs);
void				verif_cone(char *line, t_objs *objs);
void				verif_cylinder(char *line, t_objs *objs);
/*
** parse_tools
*/
void				error(uint8_t mod);
int					convert_color(char *color);
void				verif_color(char *color);

/*
** main functions, they calls the others functions
*/
void				raytracing(t_objs objs, t_cam cam, t_sdl sdl);
void				throw_ray(t_ray *ray, t_objs objs, uint32_t *color);

/*
**function that takes care of the light
*/
uint32_t			ft_color(t_pt inter, t_objs objs, t_ray r, uint32_t color);

/*
** color_tools
*/
uint32_t			color_add(uint32_t color, uint32_t add);
uint32_t			color_mul(uint32_t color, double add);

/*
** mathematics function, they check if we touch figures
*/
double				check_sphere(t_sphere sphere, t_ray ray);
double				check_plan(t_plan plan, t_ray ray);
double				check_cone(t_cone cone, t_ray ray);
double				check_cylinder(t_cylinder cyl, t_ray ray);

/*
** free functions
*/
void				end(int escape, t_sdl sdl, t_objs objs);
void				free_split(char **tab1, char **tab2, char **tab3);
void				free_sdl(t_sdl sdl);

/*
** normal functions
*/
t_vec				normal_cone(t_cone cone, t_ray ray);
t_vec				normal_cylinder(t_cylinder cyl, t_ray ray);
t_vec				normal_sphere(t_sphere sphere, t_ray ray);
t_vec				normal_plan(t_plan plan, t_ray ray);

#endif
