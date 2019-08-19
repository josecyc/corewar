int		check_name_old(t_vars *ob, char *line, int fd)
{
	char	**inst;
	char	*jointline;
	char	*str;

	inst = ft_strsplit(line, "\"\"\"");
	str = ft_strtrim(inst[0]);
	if (inst[1])
		jointline = ft_strdup(inst[1]);
	else
		jointline = ft_strdup("Default");
	if (ft_strcmp(NAME_CMD_STRING, str) == 0 ||
			ft_strcmp(COMMENT_CMD_STRING, str) == 0)
	{
		if (strlastchr(line, '\"') == -1 && inst[1])
			jointline = join_quotes(inst[1], fd, ob);
		if (ft_strcmp(NAME_CMD_STRING, str) == 0 && ft_strlen(jointline)
				<= PROG_NAME_LENGTH)	
		{
			ob->player_name = ft_strdup(jointline);
		}
		if (ft_strcmp(COMMENT_CMD_STRING, str) == 0 && ft_strlen(jointline)
				<= COMMENT_LENGTH)	
			ob->comment = ft_strdup(jointline);
		ob->begin_line = ob->counter;
		free_split(inst);
		free(str);
		free(jointline);
		return (1);
	}
	else
		return (-1);
}

char	*join_quotes(char *str, int fd, t_vars *ob)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	while (!ft_strchr(str, '"'))
	{
		get_next_line(fd, &line);
		ob->counter++;
		tmp = ft_strdup(str);
		str = ft_strjoin(tmp, line);
		if (line && line[0])
			free(line);
		free(tmp);
	}
	i = ft_strlen(str);
	i--;
	str[i] = '\0';
	return (str);
}

int		strlastchr(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	i--;
	if (str[i] == c)
		return (1);
	else
		return (-1);
}
