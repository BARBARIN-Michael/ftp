/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_srv_insert.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 15:01:56 by barbare           #+#    #+#             */
/*   Updated: 2016/01/09 18:00:53 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_SRV_INSERT_H
# define FUNCTION_SRV_INSERT_H

# define NBR_ARGS 25
# define NBR_CHAR 255

typedef struct		s_fct t_fct;

struct				s_fct
{
	void			*fct;
	unsigned char	nbrparam;
	char			args[NBR_ARGS][NBR_CHAR]
};

#endif
