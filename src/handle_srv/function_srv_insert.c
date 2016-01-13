/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_srv_insert.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 14:48:47 by barbare           #+#    #+#             */
/*   Updated: 2016/01/09 18:03:26 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/syslimits.h>

static void		fct_fill(tfct *fct)
{
	ft_bzero(fct, sizeof(t_fct));
	env->fct[0].fct = &exit;
}
