void setup() {
  // put your setup code here, to run once:
  Serial1.begin(115200);
}
unsigned long count = 0;
void loop() {
  // put your main code here, to run repeatedly:
  Serial1.println(count);
  delay(100);
}
