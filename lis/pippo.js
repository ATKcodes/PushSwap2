#!use strict

function lis(stack) {
	let	cur_max = [];
	let cur_lis = [];

	for (let i = 0; i < stack.length; i++) {//* slice = NUOVO array che va da startIndex a endIndex, endIndex NON INCLUSO [startIndex, endIndex)
		cur_lis = lis_rec(stack.slice(0, i), [stack[i]]);
		if (cur_lis.length > cur_max.length)
		{
			cur_max = cur_lis.slice(0);
		}
	}
	return (cur_max);
}

function lis_rec(stack, cur_lis)
{
	let	witho	 = [];
	let	withouto = [];
	let	new_cur_lis;

	if (0 == stack.length)
		return (cur_lis);
	else {
		if (stack[stack.length - 1] > cur_lis[0])
			return (lis_rec(stack.slice(0, stack.length - 1), cur_lis));
		else {
			new_cur_lis = cur_lis.slice(0); cur_lis.unshift(stack[stack.length - 1]);
			witho = lis_rec(
				stack.slice(0, stack.length - 1),//* unshift = aggiungi all'inizio
				new_cur_lis
				);
			withouto = lis_rec(
				stack.slice(0, stack.length - 1),
				cur_lis.slice(0)
			);

			if (withouto.length > witho.length)
				return (withouto);
			else
				return (witho)
		}
	}
}

let sol = lis([5, 3, 10, 8, 9, 1, 14, 2, 12]);
console.log(sol);
console.log(`lis len: ${sol.length}`);