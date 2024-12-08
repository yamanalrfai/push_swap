# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_push_swap.py                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataher <ataher@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/08 12:57:18 by ataher            #+#    #+#              #
#    Updated: 2024/12/08 12:57:18 by ataher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import random
import subprocess
import argparse

oparations = []

min_range = -500
max_range = 500


def run_push_swap(numbers_count):
	numbers = random.sample(range(min_range, max_range), numbers_count)

	numbers_str = " ".join(map(str, numbers))

	command_append = f"./push_swap {numbers_str}"
	command_count = f"./push_swap {numbers_str} | wc -l"

	result = subprocess.run(command_count, shell=True, stdout=subprocess.PIPE, text=True)

	print(f"\n\n{command_append}")
	print(f"\033[92mOperations: {int(result.stdout.strip().split()[0])}\033[0m\n\n")

	oparations.append(int(result.stdout.strip().split()[0]))

if __name__ == "__main__":
	parser = argparse.ArgumentParser()
	parser.add_argument("numbers_count", type=int)
	parser.add_argument("run_program_count", type=int)

	args = parser.parse_args()

	for _ in range(args.run_program_count):
		run_push_swap(args.numbers_count)

	print(f"\033[94mTest ran successfully {args.run_program_count} times, with {args.numbers_count} random numbers in the range {min_range} to {max_range}\033[0m")
	print(f"Average operations: {sum(oparations) / len(oparations)}")
	print(f"Max operations: {max(oparations)}")
	print(f"Min operations: {min(oparations)}")
	print(f"90% of data lay between: {sorted(oparations)[int(len(oparations) * 0.1)]} and {sorted(oparations)[int(len(oparations) * 0.9)]}")
