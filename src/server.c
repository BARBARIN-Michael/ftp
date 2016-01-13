/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 10:51:33 by mbarbari          #+#    #+#             */
/*   Updated: 2016/01/09 18:04:49 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft.h"

static int	init_env(t_env *env)
{
	ft_bzero(env, sizeof(t_env));
	ft_stream_new(STDIN, STDOUT, STDERR, &env.stream);
	return (1);
}

static void	loop(t_srv *srv)
{
	static int		init = 0;
	t_env			env; //TODO: permet de sauvegarder les differentes fonctions serveur entre autre
	t_cmd			cmd; //TODO: Permet de sauvegarder la totalite de la chaine parsee;
	void			*function;

	init = (init == 0) ? init_env(&env) : 1;
	ft_printf("%sFTP > %s", C_GREEN, C_NONE);
	if (ft_stream_fill(&env.stream) != 0)
		if (ft_parse_cmd(env, cmd))
			launched_function(env, cmd);
	else
		loop(srv);
}

int			main(int argc, char **argv)
{
	unsigned int	ret;
	t_srv			srv;

	if (argc == 2)
	{
		//TODO: test la conformite de la valeur d'entree, ici si c'est un nombre
		if (ft_isnumber(argv[1]))
			loop(setup_srv((t_srv){.port = ft_atoi(argv[1])}));
		else
			N_ERR(server_error(500), argv[1]);
	}
	return (ret);
}
