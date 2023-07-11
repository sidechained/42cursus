int map_z_to_colour(float value, float min_z, float max_z)
{
	float normalized_z;
	int colour;

	normalized_z = (value - min_z) / (max_z - min_z);
	colour = (int)(normalized_z * 255);
	if (colour < 0)
		colour = 0;
	else if (colour > 255)
		colour = 255;
	return (colour);
}

void find_min_max_z(t_point **matrix, t_data *data)
{
	float current_z;
	unsigned int irow;
	unsigned int icol;

	data->min_z = matrix[0][0].z;
	data->max_z = matrix[0][0].z;
	irow = 0;
	while (irow < data->nrows)
	{	
		icol = 0;
		while (icol < data->ncols)
		{
			current_z = matrix[irow][icol].z;
			if (current_z < data->min_z)
				data->min_z = current_z;
			if (current_z > data->max_z)
				data->max_z = current_z;
			icol++;
		}
		irow++;
	}
}