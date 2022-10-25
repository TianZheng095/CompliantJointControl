function eul = q2eul(robot,q,bodyname)
    Transform = getTransform(robot,q,bodyname);      
    eul = rotm2eul(Transform(1:3,1:3),'XYZ')';
    
end

