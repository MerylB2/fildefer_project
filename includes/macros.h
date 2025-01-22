/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiatik <asiatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:44:41 by asiatik           #+#    #+#             */
/*   Updated: 2025/01/21 02:28:43 by asiatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

/* Couleurs par défaut */
# define COLOR_WHITE 0xFFFFFF
# define COLOR_BLACK 0x000000
# define COLOR_RED   0xFF0000
# define COLOR_GREEN 0x00FF00
# define COLOR_BLUE  0x0000FF
# define COLOR_YELLOW 0xFFFF00

/* Dimensions par défaut */
# define WIN_WIDTH 1280  // Largeur de la fenêtre
# define WIN_HEIGHT 720  // Hauteur de la fenêtre

/* Clavier (codes pour Linux/Mac) */
# define ESC_KEY 65307     // Touche ESC
# define ARROW_UP 65362    // Flèche haut
# define ARROW_DOWN 65364  // Flèche bas
# define ARROW_LEFT 65361  // Flèche gauche
# define ARROW_RIGHT 65363 // Flèche droite
# define ZOOM_IN 65451     // Touche "+"
# define ZOOM_OUT 65453    // Touche "-"
# define ROTATE_LEFT 113   // Touche "Q"
# define ROTATE_RIGHT 101  // Touche "E"

/* Projections */
# define ISO_ANGLE 0.523599 // 30° en radians
# define ZOOM_DEFAULT 20    // Zoom initial
# define OFFSET_DEFAULT 0   // Décalage initial

/* Messages d'erreur */
# define ERR_FILE_OPEN "Error: Unable to open file."
# define ERR_FILE_FORMAT "Error: Invalid file format."
# define ERR_MEMORY_ALLOC "Error: Memory allocation failed."
# define ERR_MLX_INIT "Error: Failed to initialize MiniLibX."
# define ERR_WINDOW_INIT "Error : Failed to initialize Window"
# define ERR_IMAGE_INIT "Error : Failed to initialize Image" 

#endif
