/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_asm_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:41:26 by medesmon          #+#    #+#             */
/*   Updated: 2020/01/15 15:23:03 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

uint8_t args_type_code(t_command *buff)
{
    uint8_t byte;
    size_t  i;

    byte = 0;
    i = 0;
    while (i < 3)
    {
        if (buff->arg[i]) {
            if (*(buff->arg[i]) == 'r')
                byte |= REG_CODE;
            else if (*(buff->arg[i]) == DIRECT_CHAR)
                byte |= DIR_CODE;
            else
                byte |= IND_CODE;
        }
        byte = byte << 2;
        i++;
    }
    return (byte);
}

void    mem_cpy(void *dst, void *src, int n)
{
    char			*ptr1;
    char			*ptr2;
    unsigned int	i;

    i = 0;
    ptr1 = (char *)dst;
    ptr2 = (char *)src;
    while (i < n)
    {
        ptr1[i] = ptr2[n - 1 - i];
        i++;
    }
}

size_t  add_arg(t_command *buff, size_t i, t_parse *champ)
{
    size_t  j;
    char    *str;
    int16_t num16;
    int32_t num32;

    num16 = 0;
    num32 = 0;
    j = 0;
    while (j < g_op[buff->type].args_num)
    {
        if (buff->arg[j])
        {
            if (*(buff->arg[j]) == 'r')
            {
                str = buff->arg[j] + 1;
                champ->exec_code[i++] = (uint8_t)ft_atoi(str);
            }
            else if (*(buff->arg[j]) == DIRECT_CHAR)
            {
                str = buff->arg[j] + 1;
                if (g_op[buff->type].t_dir_size == 4) {
                    num32 = ft_atoi(str);
                    mem_cpy(champ->exec_code + i, &num32, g_op[buff->type].t_dir_size);
                }
                else {
                    num16 = ft_atoi(str);
                    mem_cpy(champ->exec_code + i, &num16, g_op[buff->type].t_dir_size);
                }
                i += g_op[buff->type].t_dir_size;
            }
            else
            {
                num16 = ft_atoi(str);
                ft_memcpy(champ->exec_code + i, &num16, 2);
                i += 2;
            }
        }
        j++;
    }
    return (i);
}

void    fill_code(t_parse *champ)
{
    t_command       *buff;
    size_t          i;

    i = 0;
    buff = champ->list_cmd;
    while (buff != NULL)
    {
        champ->exec_code[i++] = g_op[buff->type].code;
        if (g_op[buff->type].args_types_code)
            champ->exec_code[i++] = args_type_code(buff);
        i = add_arg(buff, i, champ);
        buff = buff->next;
    }
}

void    to_asm_code(t_parse *champ) // заинитить size = 0;
{
    t_command       *buff;
    int             i;

    buff = champ->list_cmd;
    while (buff != NULL)
    {
        champ->size += sizing(buff);
        buff = buff->next;
    }
    if (!(champ->exec_code = (uint8_t *)malloc(sizeof(uint8_t) * champ->size)))
        error("Память не выделилась!", -1);
    i = 0;
    while (i < champ->size)
        champ->exec_code[i++] = 0;
    fill_code(champ);
}