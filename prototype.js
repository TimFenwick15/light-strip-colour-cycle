const grad = (angle, angleOffset = 0) => {
  angle = angle + angleOffset
  if (angle > 360)
    angle -= 360
  const min = 66
  const max = 244
  let amp
  if (angle < 60)
    amp = min + Math.floor( angle * (max - min) / 60 )
  else if (angle >= 60 && angle < 180)
    amp = max
  else if (angle >= 180 && angle < 240)
    amp = max - Math.floor( (angle - 180) * (max - min) / 60 ) 
  else
    amp = min
  return amp
}

for (let i = 0; i < 360; i += 10)
  console.log(grad(i, 240))

// use 0, 120 and 240

