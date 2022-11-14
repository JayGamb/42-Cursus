/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:56:51 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/14 17:53:01 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_dectohex(int decimal)
{

	char reversedDigits[100];
	int i = 0;
	
	while(decimal > 0) {
		
		int remain = decimal % 16;
		
		if(remain < 10)
			reversedDigits[i] = '0' + remain;
		else
			reversedDigits[i] = 'A' + (remain - 10);
		
		decimal = decimal / 16;
		i++;
	}
	
	printf("Hexadecimal number: ");
	while(i--) {
		
		ft_putchar(reversedDigits[i]);
	}
}
