
#include "internal_printf.h"

static char g_buf[MAX_BUF_LEN];

extern void putchar(char c);

/*
 * WARNING: For color, buffer is not enabled
 */
void	fflush_buffer(t_status *op)
{
	if (!op->str) {
		for (int i = 0; i < op->buff_len; i++)
			putchar(g_buf[i]);
	} else {
		ft_memcpy(op->str, g_buf, op->buff_len);
		op->str += op->buff_len;
	}
	op->total_size += op->buff_len;
	op->buff_len = 0;
}

void	string_to_buffer(const char *s, int len, t_status *op)
{
	int i;

	while (len > (MAX_BUF_LEN - op->buff_len)) {
		i = MAX_BUF_LEN - op->buff_len;
		ft_memcpy(g_buf + op->buff_len, s, i);
		s += i;
		op->buff_len += i;
		fflush_buffer(op);
		len -= i;
	}
	ft_memcpy(g_buf + op->buff_len, s, len);
	op->buff_len += len;
	fflush_buffer(op);				// No buffer
}

void	char_to_buffer(char c, int len, t_status *op)
{
	int i;

	while (len > (MAX_BUF_LEN - op->buff_len)) {
		i = MAX_BUF_LEN - op->buff_len;
		ft_memset(g_buf + op->buff_len, c, i);
		op->buff_len += i;
		fflush_buffer(op);
		len -= i;
	}
	ft_memset(g_buf + op->buff_len, c, len);
	op->buff_len += len;
	fflush_buffer(op);				// No buffer
}
