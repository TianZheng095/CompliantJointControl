function x = q2x(robot,q,bodyname)
    Transform = getTransform(robot,q,bodyname);      
    x = Transform(1:3,4);
    
end

