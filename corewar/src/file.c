/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:40:57 by medesmon          #+#    #+#             */
/*   Updated: 2020/01/15 14:49:36 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		write_bytecode_file(int fd, t_parse *champ)
{
    int32_t	len;
    int32_t	pos;
    uint8_t	*bytecode;
    int32_t i;


    pos = 0;
    len = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4 + champ->size;
    if (!(bytecode = (uint8_t *)ft_strnew((size_t)len)))
        error("Память для байт кода не выделена!", -1);
    i = COREWAR_EXEC_MAGIC;
    mem_cpy(&bytecode[pos], &i, 4);
    pos += 4;
    ft_memcpy(&bytecode[pos], champ->name, ft_strlen(champ->name));
    pos += PROG_NAME_LENGTH;
    pos += 4;
    mem_cpy(&bytecode[pos], &(champ->size), 4);
    pos += 4;
    ft_memcpy(&bytecode[pos], champ->comment, ft_strlen(champ->comment));
    pos += COMMENT_LENGTH;
    pos += 4;
    ft_memcpy(&bytecode[pos], champ->exec_code, (size_t)champ->size);
    write(fd, bytecode, (size_t)len);
    free(bytecode);
}
