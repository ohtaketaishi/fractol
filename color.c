#include "fractol.h"

int color(t_p *p)
{
	if (p->c % 3 == 0)
		return (rainbow(p));
	else if (p->c % 3 == 1)
		return (black(p));
	else
		return (white(p));
}

int	rainbow(t_p *p)
{
	if(p->n % 7 == 0 || p->n == -1)
		return(0x00FF0000);//red
	else if(p->n % 7 == 1)
		return(0x00FFa500);//orange
	else if(p->n % 7 == 2)
		return(0x00FFFF00);//yellow
	else if(p->n % 7 == 3)
		return(0x00008000);//green
	else if(p->n % 7 == 4)
		return(0x0000FFFF);//light blue
	else if(p->n % 7 == 5)
		return(0x000000FF);//blue
	else
		return(0x00800080);//purple
}

int	black(t_p *p)
{
	if (p->n == -1)
		return (0x00000000);
	return(p->n % 100 * pow(2, 12) + 0x00000000);
}

int	white(t_p *p)
{
	if (JULIA1 <= p->fractol && p->fractol <= JULIA3)
		return (black(p));
	else if (p->n == -1)
		return (0x00FFFFFF);
	else
		return (0x00000000);
}
