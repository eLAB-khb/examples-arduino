/* --------------------------------------------------------------------------------
 * utility function to visualize percentages (0.0 … 1.0) in the serial monitor
 */
void printPercentage(float p)
{
  int n = 20;
  for (int i = 0; i < n; i++)
  {
    if(i < p*n)
    Serial.print("#");
    else
    Serial.print("-");
  }
}

/* --------------------------------------------------------------------------------
 * utility function to print the current motor settings to the serial monitor
 */
void printInfo(String id, boolean dir, float vel)
{
  Serial.print("Motor " + id + ":");
  Serial.print("\tDirection: "); Serial.print(dir);
  Serial.print("\tSpeed: "); Serial.print(vel);Serial.print("\t");printPercentage(vel);
  Serial.println();
}