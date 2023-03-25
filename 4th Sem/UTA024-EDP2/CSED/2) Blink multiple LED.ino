int lpins [3]={13, 12,8};
void setup() {
for (int i=0;i<3;i++)
{
pinMode(lpins [i],OUTPUT);
}
}
void loop()
{
for (int i=0;i<3;i++) {
digitalWrite(lpins [i],HIGH);
digitalWrite(lpins[i], LOW);
