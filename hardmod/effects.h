void efx0_row(struct update_s*);
void efx1_row(struct update_s*);
void efx2_row(struct update_s*);
void efx3_row(struct update_s*);
void efx4_row(struct update_s*);
void efx5_row(struct update_s*);
void efx6_row(struct update_s*);
void efx7_row(struct update_s*);
void efx8_row(struct update_s*);
void efx9_row(struct update_s*);
void efxA_row(struct update_s*);
void efxB_row(struct update_s*);
void efxC_row(struct update_s*);
void efxD_row(struct update_s*);
void efxE_row(struct update_s*);
void efxF_row(struct update_s*);
void efx0_tick(struct update_s*);
void efx1_tick(struct update_s*);
void efx2_tick(struct update_s*);
void efx3_tick(struct update_s*);
void efx4_tick(struct update_s*);
void efx5_tick(struct update_s*);
void efx6_tick(struct update_s*);
void efx7_tick(struct update_s*);
void efx8_tick(struct update_s*);
void efx9_tick(struct update_s*);
void efxA_tick(struct update_s*);
void efxB_tick(struct update_s*);
void efxC_tick(struct update_s*);
void efxD_tick(struct update_s*);
void efxE_tick(struct update_s*);
void efxF_tick(struct update_s*);

typedef void (*pEffect)(struct update_s*);
pEffect roweffect[16] =
{
	efx0_row,
	NULL,//efx1_row,
	NULL,//efx2_row,
	efx3_row,
	efx4_row,
	NULL,//efx5_row,
	NULL,//efx6_row,
	NULL,//efx7_row,
	efx8_row,
	NULL,//efx9_row,
	NULL,//efxA_row,
	efxB_row,
	efxC_row,
	efxD_row,
	efxE_row,
	efxF_row	
};
pEffect tickeffect[16] =
{
	efx0_tick,
	efx1_tick,
	efx2_tick,
	efx3_tick,
	efx4_tick,
	efx5_tick,
	efx6_tick,
	NULL,//efx7_tick,
	NULL,//efx8_tick,
	NULL,//efx9_tick,
	efxA_tick,
	NULL,//efxB_tick,
	NULL,//efxC_tick,
	NULL,//efxD_tick,
	efxE_tick,
	NULL//efxF_tick		
};
