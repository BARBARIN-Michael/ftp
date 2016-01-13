/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 11:54:20 by barbare           #+#    #+#             */
/*   Updated: 2016/01/11 16:43:38 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "ft_stream.h"

# define FCTS_NBR 25

typedef struct	s_env t_env;

struct			s_env
{
	t_stream	stream;
	t_fct		fct[FCT_NBR];
};

#endif
