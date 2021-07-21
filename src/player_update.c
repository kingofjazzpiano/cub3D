#include "main.h"

// delta_time version
void	player_update(t_plr *player, int key_flags, double delta_time)
{	
	player->move_speed = player->normal_speed;
	if (key_flags & SHIFT)
		player->move_speed *= 2;
	player->rotation_angle += ROTATION_SPEED * player->turn_direction * delta_time;
	if (player->rotation_angle < 0)
		player->rotation_angle += PI2;
	if (player->rotation_angle > PI2)
		player->rotation_angle -= PI2;
	player->delta_x = cos(player->rotation_angle) * player->move_speed * delta_time;
	player->delta_y = sin(player->rotation_angle) * player->move_speed * delta_time;
	player->pos.x += player->delta_x * player->walk_direction;
	player->pos.y += player->delta_y * player->walk_direction;
	if (player->strafe_direction && player->walk_direction)
		player->move_speed = player->diagonal_speed;
	else
		player->move_speed = player->normal_speed;
	if (LEFT == player->strafe_direction)
	{
		player->pos.x += cos(player->rotation_angle - PI_DIV_2) * player->move_speed * delta_time;
		player->pos.y += sin(player->rotation_angle - PI_DIV_2) * player->move_speed * delta_time;
	}
	if (RIGHT == player->strafe_direction)
	{
		player->pos.x += cos(player->rotation_angle + PI_DIV_2) * player->move_speed * delta_time;
		player->pos.y += sin(player->rotation_angle + PI_DIV_2) * player->move_speed * delta_time;
	}
}

// void	player_update(t_plr *plr, int key_flags)
// {
// 	plr->move_speed = plr->normal_speed;
// 	if (key_flags & SHIFT)
// 		plr->move_speed *= 2;
// 	plr->rotation_angle += ROTATION_SPEED * plr->turn_direction;
// 	if (plr->rotation_angle < PI)
// 		plr->rotation_angle += PI2;
// 	if (plr->rotation_angle > PI)
// 		plr->rotation_angle -= PI2;
// 	plr->delta_x = cos(plr->rotation_angle) * plr->move_speed;
// 	plr->delta_y = sin(plr->rotation_angle) * plr->move_speed;
// 	plr->pos.x += plr->delta_x * plr->walk_direction;
// 	plr->pos.y += plr->delta_y * plr->walk_direction;
// 	if (plr->strafe_direction && plr->walk_direction)
// 		plr->move_speed /= SQRT2;
// 	if (LEFT == plr->strafe_direction)
// 	{
// 		plr->pos.x += cos(plr->rotation_angle - PI_DIV_2) * plr->move_speed;
// 		plr->pos.y += sin(plr->rotation_angle - PI_DIV_2) * plr->move_speed;
// 	}
// 	if (RIGHT == plr->strafe_direction)
// 	{
// 		plr->pos.x += cos(plr->rotation_angle + PI_DIV_2) * plr->move_speed;
// 		plr->pos.y += sin(plr->rotation_angle + PI_DIV_2) * plr->move_speed;
// 	}
// }
