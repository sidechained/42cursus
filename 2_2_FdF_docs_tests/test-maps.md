# Test Maps

## Parsed as expected:
make re; ./fdf test_maps/100-6.fdf
make re; ./fdf test_maps/3x3error.fdf
make re; ./fdf test_maps/basictest.fdf
make re; ./fdf test_maps/elem.fdf
make re; ./fdf test_maps/pyra.fdf
make re; ./fdf test_maps/pentenegpos.fdf
make re; ./fdf test_maps/xxx.fdf
make re; ./fdf test_maps/10-2.fdf
make re; ./fdf test_maps/3x3.fdf
make re; ./fdf test_maps/basictest-zero.fdf
make re; ./fdf test_maps/plat.fdf
make re; ./fdf test_maps/10-70.fdf
make re; ./fdf test_maps/42.fdf
make re; ./fdf test_maps/elem2.fdf
make re; ./fdf test_maps/pnp_flat.fdf
make re; ./fdf test_maps/20-60.fdf
make re; ./fdf test_maps/50-4.fdf
make re; ./fdf test_maps/mars.fdf

## Expected errors due to colour data inside the matrix:
make re; ./fdf test_maps/elem-fract.fdf // error CORRECT
make re; ./fdf test_maps/pyramide.fdf  // error CORRECT
make re; ./fdf test_maps/julia.fdf  // error CORRECT
make re; ./fdf test_maps/t1.fdf  // error CORRECT
make re; ./fdf test_maps/elem-col.fdf  // error CORRECT
make re; ./fdf test_maps/t2.fdf  // error CORRECT

## Expected errors due to differences in row elements:
make re; ./fdf test_maps/pylone.fdf // error retrieving matrix dimensions

