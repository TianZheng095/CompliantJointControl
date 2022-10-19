% Example_Joint

classdef Example_Joint < genericJoint

	properties (SetAccess = private)
	end

	methods
		%CONSTRUCTOR Template for joint class constructor
		%
		% Author::
		%  Joern Malzahn
		%  Wesley Roozing
		%
		% See also genericJoint, jointBuilder, getNonlinearDynamics.
		
		% Copyright (C) 2016, by Joern Malzahn, Wesley Roozing
		%
		% This file has been generated with the Compliant Joint Toolbox (CJT).
		%
		% CJT is free software: you can redistribute it and/or modify
		% it under the terms of the GNU General Public License as published by
		% the Free Software Foundation, either version 3 of the License, or
		% (at your option) any later version.
		%
		% CJT is distributed in the hope that it will be useful, but WITHOUT ANY
		% WARRANTY; without even the implied warranty of MERCHANTABILITY or
		% FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public
		% License for more details.
		%
		% You should have received a copy of the GNU General Public License
		% along with CJT. If not, see <http://www.gnu.org/licenses/>.
		%
		% For more information on the toolbox and contact to the authors visit
		% <https://github.com/geez0x1/CompliantJointToolbox>
		function this = Example_Joint
		    % Model parameters
			%% Motor parameters
			% Save these lines in example_params.m
			% for later use in other examples.
			%
			% Motor rotor inertia [kg m^2]
			params.('I_m') = 9.407000e-02;     
			% Motor Damping [Nms/rad]
			params.('d_m') = 2.188643e-03;
			% Torque constant [Nm/A]
			params.('k_t') = 4.100000e-02;
			
			%% Gear parameters
			% Gear transmission ratio [.]
			params.('n')   = 100;
			
			%% Sensor parameters
			% Sensor inertia [kg m^2]
			params.('I_l') = 1.137000e-04;
			% Sensor stiffness [Nm/rad]
			params.('k_b') = 21000;     
			
		
		    % Sourced params and models
		    params.('name')                 = 'Example_Joint'; % Joint name
		    params.('paramName')            = 'example_params'; % Parameter name
		    params.('modelName')            = 'output_fixed_rigid_gearbox'; % Model name
		    params.('nonlinearModelName')   = {'coulomb', 'viscous_asym'}; % Nonlinear model name(s)
		    params.('electricalModelName')  = 'electric_dyn'; % Electrical model name
		    
		    % Build joint
		    this = this@genericJoint(params);
		end
		

		%GETDYNAMICSMATRICES Template for obtaining state space matrices for the linear dynamics.
		%
		% [A, B, C, D, I, R, K] = jointObj.getDynamicsMatrices
		%
		% jointObj is the instance of the joint class object for which this
		% function has been called.
		%
		% Outputs::
		%
		%
		%   A: System matrix
		%   B: Input matrix
		%   C: Output matrix
		%   D: Direct Feedthrough matrix
		%   I: Inertia matrix
		%   R: Damping matrix
		%   K: Stiffness matrix
		%
		% Notes::
		%
		%
		% Examples::
		%
		% Author::
		%  Joern Malzahn
		%  Wesley Roozing
		%
		% See also genericJoint, full_dyn, getNonlinearDynamics.
		
		% Copyright (C) 2016, by Joern Malzahn, Wesley Roozing
		%
		% This file is part of the Compliant Joint Toolbox (CJT).
		%
		% CJT is free software: you can redistribute it and/or modify
		% it under the terms of the GNU General Public License as published by
		% the Free Software Foundation, either version 3 of the License, or
		% (at your option) any later version.
		%
		% CJT is distributed in the hope that it will be useful, but WITHOUT ANY
		% WARRANTY; without even the implied warranty of MERCHANTABILITY or
		% FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public
		% License for more details.
		%
		% You should have received a copy of the GNU General Public License
		% along with CJT. If not, see <http://www.gnu.org/licenses/>.
		%
		% For more information on the toolbox and contact to the authors visit
		% <https://github.com/geez0x1/CompliantJointToolbox>
		function [A, B, C, D, I, R, K] = getDynamicsMatrices(obj)
		    [A, B, C, D, I, R, K] = output_fixed_rigid_gearbox(obj);
		end
		

		%GETNONLINEARDYNAMICS Template for obtaining the linear dynamics expression.
		%
		% [tau, y] = jointObj.getNonlinearDynamics(x)
		%
		% jointObj is the instance of the joint class object for which this
		% function has been called.
		%
		% Inputs:: 
		%   x: state vector
		%
		% Outputs::
		%   tau: Generalized force vector
		%   y:   Nonlinear output components
		%
		% Notes::
		%
		%
		% Examples::
		%
		% Author::
		%  Joern Malzahn
		%  Wesley Roozing
		%
		% See also genericJoint, full_dyn, getDynamicsMatrices.
		
		% Copyright (C) 2016, by Joern Malzahn, Wesley Roozing
		%
		% This file is part of the Compliant Joint Toolbox (CJT).
		%
		% CJT is free software: you can redistribute it and/or modify
		% it under the terms of the GNU General Public License as published by
		% the Free Software Foundation, either version 3 of the License, or
		% (at your option) any later version.
		%
		% CJT is distributed in the hope that it will be useful, but WITHOUT ANY
		% WARRANTY; without even the implied warranty of MERCHANTABILITY or
		% FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public
		% License for more details.
		%
		% You should have received a copy of the GNU General Public License
		% along with CJT. If not, see <http://www.gnu.org/licenses/>.
		%
		% For more information on the toolbox and contact to the authors visit
		% <https://github.com/geez0x1/CompliantJointToolbox>
		function [tau, y] = getNonlinearDynamics(obj, x)
		    
[tau_1, y_1] = coulomb(obj, x);
[tau_2, y_2] = viscous_asym(obj, x);
tau = tau_1 +tau_2;
y = y_1 +y_2;
		end
		

		%GETELECTRICALDYNAMICSMATRICES Template for obtaining state space matrices for the linear electrical dynamics.
		%
		% [A, B, C, D] = jointObj.getElectricalDynamicsMatrices
		%
		% jointObj is the instance of the joint class object for which this
		% function has been called.
		%
		% Outputs::
		%
		%
		%   A: System matrix
		%   B: Input matrix
		%   C: Output matrix
		%   D: Direct Feedthrough matrix
		%
		% Notes::
		%
		%
		% Examples::
		%
		% Author::
		%  Joern Malzahn
		%  Wesley Roozing
		%
		% See also genericJoint, full_dyn, getNonlinearDynamics.
		
		% Copyright (C) 2016, by Joern Malzahn, Wesley Roozing
		%
		% This file is part of the Compliant Joint Toolbox (CJT).
		%
		% CJT is free software: you can redistribute it and/or modify
		% it under the terms of the GNU General Public License as published by
		% the Free Software Foundation, either version 3 of the License, or
		% (at your option) any later version.
		%
		% CJT is distributed in the hope that it will be useful, but WITHOUT ANY
		% WARRANTY; without even the implied warranty of MERCHANTABILITY or
		% FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public
		% License for more details.
		%
		% You should have received a copy of the GNU General Public License
		% along with CJT. If not, see <http://www.gnu.org/licenses/>.
		%
		% For more information on the toolbox and contact to the authors visit
		% <https://github.com/geez0x1/CompliantJointToolbox>
		function [A, B, C, D] = getElectricalDynamicsMatrices(obj)
		    [A, B, C, D] = electric_dyn(obj);
		end
		

	end

end
