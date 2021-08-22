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
