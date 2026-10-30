#include <stdio.h>

int main()
{
    double h; // height
    double w; // width
    double d; // depth

    printf("Enter height of shelf in centimeters from 180 to 220: ");
    scanf("%lf", &h);

    printf("Enter width of shelf in centimeters from 80 to 120: ");
    scanf("%lf", &w);

    printf("Enter depth of shelf in centimeters from 50 to 90: ");
    scanf("%lf", &d);

    double chipboard_density;
    double fiberboard_density;
    double wood_density;

    printf("Enter chipboard density in kg/m^3: ");
    scanf("%lf", &chipboard_density);

    printf("Enter fiberboard density in kg/m^3: ");
    scanf("%lf", &fiberboard_density);

    printf("Enter wood density in kg/m^3: ");
    scanf("%lf", &wood_density);

    double h_m = h / 100;
    double w_m = w / 100;
    double d_m = d / 100;

    double shelf_mass = 0;

    // Attached back panel made of fiberboard
    shelf_mass += (h_m * w_m * (0.5 / 100)) * fiberboard_density;

    // Two side panels made of chipboard
    shelf_mass += 2 * (h_m * d_m * (1.5 / 100)) * chipboard_density;

    // Top and bottom cover panels made of chipboard
    shelf_mass += 2 * (w_m * d_m * (1.5 / 100)) * chipboard_density;

    // Two wooden overlay doors
    shelf_mass += (h_m * w_m * (1 / 100)) * wood_density;

    int shelves_count = h_m / 0.4 - 1;

    if (shelves_count > 0)
        shelf_mass += shelves_count * (w_m * d_m * (1.5 / 100)) * chipboard_density;

    printf("Total shelf mass: %.2f kg\n", shelf_mass);

    return 0;
}